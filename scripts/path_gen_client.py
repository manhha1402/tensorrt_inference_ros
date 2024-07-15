from neura_path_generator_msgs.srv import SnpTpp
from neura_vision_tools_msgs.msg import Mesh
import rclpy
from rclpy.node import Node
import open3d as o3d
from pathlib import Path
from neura_vision_tools_py.utils.conversions import mesh_from_open3d_to_nvt


class MinimalClientAsync(Node):

    def __init__(self):
        super().__init__('minimal_client_async')
        self.cli = self.create_client(
            SnpTpp, 'neura_snp_path_generator/generate_toolpaths')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = SnpTpp.Request()

    def send_request(self, mesh_msg: Mesh, frame_id: str, largest_principal_axis: bool, min_hole_size: float,
                     min_segment_size: float, raster_rot_offset: float, search_radius: float, waypoint_orientation_modifier: float,
                     point_spacing: float, raster_spacing: float):
        self.req.mesh = mesh_msg
        self.req.frame_id = frame_id
        self.req.largest_principal_axis = largest_principal_axis
        self.req.min_hole_size = min_hole_size
        self.req.min_segment_size = min_segment_size
        self.req.raster_rot_offset = raster_rot_offset
        self.req.search_radius = search_radius
        self.req.waypoint_orientation_modifier = waypoint_orientation_modifier
        self.req.point_spacing = point_spacing
        self.req.raster_spacing = raster_spacing

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()


def main(args=None):
    rclpy.init(args=args)
    snp_dir = Path.home()/'data'/'snp'
    o3d_mesh = o3d.io.read_triangle_mesh(snp_dir.as_posix() + '/test.ply')
    frame_id = 'root_link'
    mesh = mesh_from_open3d_to_nvt(o3d_mesh=o3d_mesh, frame_id=frame_id)

    minimal_client = MinimalClientAsync()
    response = minimal_client.send_request(mesh_msg=mesh, frame_id=frame_id, largest_principal_axis=True, min_hole_size=0.02, min_segment_size=0.01,
                                           raster_rot_offset=0.0, search_radius=0.02, waypoint_orientation_modifier=3, point_spacing=0.02, raster_spacing=0.02)
    print(response.rc)
    print(response.tool_paths)

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
