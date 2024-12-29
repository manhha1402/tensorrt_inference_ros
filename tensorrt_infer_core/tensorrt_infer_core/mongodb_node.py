#!/usr/bin/env python3
import pymongo
from pymongo import MongoClient
import tensorrt_inference_py
import yaml
from pathlib import Path
import cv2
import argparse
class MongodbNode():

    def __init__(self, data_path: str)->None:
        print("Hello world from the Python node mongodb_node")
        mongo_uri = "mongodb://localhost:27017"
        # Create a MongoClient to the running MongoDB instance
        try:
            self.client = pymongo.MongoClient(mongo_uri,serverSelectionTimeoutMS = 2.0)   
        except pymongo.errors.ServerSelectionTimeoutError as err:
            print(f"Error connecting to MongoDB: {err}")
            raise RuntimeError("MongoDB connection error, if you are using external PC to connect robot, "
            "please add your ip address to /etc/mongod.conf in your robot pc and run sudo systemctl restart mongod")
        print(data_path)
        self._face_recognition_dir = Path(data_path)
    def print_database_info(self, db_name:str)->None:
        if db_name not in self.client.list_database_names():
            self.get_logger().error(f"No {db_name} in the database")
            return
        db = self.client[db_name]

        # Verify access by listing collections in this database
        collections = db.list_collection_names()
        print(f"Collections in {db_name}:", collections)
        # Print information about each collection
        for collection_name in collections:
            collection = db[collection_name]
            # Get the number of documents in the collection
            document_count = collection.count_documents({})
            # Get index information
            index_info = collection.index_information()
            documents = collection.find()
            # Print each document in the collection
            for document in documents:
                print(document)    

    #Tao thong tin khuon mat tu hinh anh, trich xuat embeddings va luu vao MongoDB
    def create_face_info(self,db_name: str , name: str)->None:
        
        if db_name in self.client.list_database_names():
            print(f"{db_name} is already in the database list")
        db = self.client[db_name]
        if name in db.list_collection_names():
            print(f"{name} is already in the collections")
            return True
        # Create a new collection (it will also be created upon first use)
        collection = db[name]
        data_dir = self._face_recognition_dir / name
        image_files = [str(path) for path in data_dir.rglob('*') if path.suffix.lower() in {'.png', '.jpg'}]
        detector = tensorrt_inference_py.detection.Detection("retinaface")
        recognizer = tensorrt_inference_py.model.Model("FaceNet_vggface2_optmized")
        params = tensorrt_inference_py.detection.DetectionParams()
        embeddings = []
     
        for i,file in enumerate(image_files) :
            image =cv2.imread(file,cv2.IMREAD_COLOR)
            print(file)
            face = detector.detect(image,params,['face'])
            cropped_face = image[face[0].rect.y:face[0].rect.y+face[0].rect.height, face[0].rect.x:face[0].rect.x+face[0].rect.width]
            embedding = recognizer.get_embedding(cropped_face)
            embeddings.append(embedding.tolist())
            #cv2.imwrite("face_" + str(i) +".jpg",cropped_face)
            cv2.imshow("face",cropped_face)
            cv2.waitKey(0)
        #embedding_list_of_lists = [arr.tolist() for arr in embeddings]

        face_info = dict()
        face_info = {
            'name': name,
            'embeddings': embeddings
        }
        # Insert the dictionary into the collection
        result = collection.insert_one(face_info)

        # Output the ID of the inserted document
        print(f"Document inserted with ID: {result.inserted_id}")



def main(args=None):

    default_face_dir = (Path.home() / 'data' / 'face_recognition').as_posix()

    parser = argparse.ArgumentParser()

    parser.add_argument(
        "--face_dir",
        dest="face_dir",
        help="face database dir",
        default=default_face_dir,
        type=str
    )
    parser.add_argument(
        "--name",
        dest="name",
        help="face name",
        type=str,
        required=True
    )

    args = parser.parse_args()
    parser.print_help()

    print(f"face_dir: {args.face_dir}")

    if not args.name:
        print(f"Please parse face name")
        exit()
    print(f"name: {args.name}")

    mongodb_node = MongodbNode(args.face_dir)
    mongodb_node.create_face_info("FaceRecognition",args.name)

if __name__ == '__main__':
    main()
