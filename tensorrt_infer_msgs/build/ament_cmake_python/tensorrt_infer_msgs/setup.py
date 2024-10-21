from setuptools import find_packages
from setuptools import setup

setup(
    name='tensorrt_infer_msgs',
    version='0.0.1',
    packages=find_packages(
        include=('tensorrt_infer_msgs', 'tensorrt_infer_msgs.*')),
)
