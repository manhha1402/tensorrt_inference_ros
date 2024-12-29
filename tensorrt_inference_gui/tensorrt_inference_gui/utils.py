import rclpy
from rclpy.node import Node

from rcl_interfaces.srv import GetParameters, ListParameters, SetParametersAtomically, SetParameters
from rcl_interfaces.msg import ParameterType, Parameter, SetParametersResult, ParameterValue
from typing import List, Tuple
import yaml
import time

class ParameterClient(Node): 
    def __init__(self):
        super().__init__('get_param_client')
    def list_parameters(self, node_name: str, remove_default_param_names: bool = True)-> List[str]:
        cli = self.create_client(ListParameters, node_name + '/list_parameters')
        while not cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('list_parameters of node: %s not available, waiting again...' %node_name)
        req = ListParameters.Request()
        future = cli.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if remove_default_param_names:
            default_param_names = ['qos_overrides./parameter_events','use_sim_time']
            names = [item for item in future.result().result.names if not any(sub in item for sub in default_param_names)]
            return names
        else :
            return future.result().result.names
    def get_parameters(self,node_name:str, names: List[str]) -> dict:
        cli = self.create_client(GetParameters, node_name + '/get_parameters')
        while not cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('get_parameters of node: %s not available, waiting again...' %node_name)
        req = GetParameters.Request()
        req.names = names
        future = cli.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        param_dict = {}
        for i in range(len(names)):
            param_dict[names[i]] = (ParameterClient.get_parameter_value(future.result().values[i]),future.result().values[i].type)
        return param_dict
    
    def set_parameters_atomically(self,node_name:str, param_dict: dict) -> SetParametersResult:
        cli = self.create_client(SetParameters, node_name + '/set_parameters')
        while not cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('set_parameters_atomically of node: %s not available, waiting again...' %node_name)
        req = SetParameters.Request()
        for key, value in param_dict.items():
            param = Parameter()
            param.name = key
            param.value = ParameterClient.set_parameter_value(value[1],value[0])
            req.parameters.append(param)
        future = cli.call_async(req)
        
         # Use manual spinning to check the status of the future
        while rclpy.ok():
        # Spin the node once to process the service response
            rclpy.spin_once(self)
        # Check if the future is done
            if future.done():
                self.get_logger().info('params are updated')
            else:
                self.get_logger().warn('params are not updated')
            return future.result()
    def save_parameters(self,node_name: str,params: List[Parameter], file_name: str) -> bool:
        yaml_output = {node_name: {'ros__parameters': {}}}
        for param in params:
            yaml_output[node_name]['ros__parameters'][param.name] = ParameterClient.get_parameter_value(param.value)
        # Save the parameters to a YAML file
        with open(file_name, 'w') as file:
            yaml.dump(yaml_output, file)
        return True
    
    def update_params(self,param_dict: dict, param_name: str,value):
        param_dict[param_name] = (value,param_dict[param_name][1])    
    @staticmethod
    def get_parameter_value(param_value:ParameterValue):
        if param_value.type == ParameterType.PARAMETER_STRING:
            return param_value.string_value
        elif param_value.type == ParameterType.PARAMETER_STRING_ARRAY:
            return param_value.string_array_value
        elif param_value.type == ParameterType.PARAMETER_INTEGER:
            return param_value.integer_value
        elif param_value.type == ParameterType.PARAMETER_INTEGER_ARRAY:
            return param_value.integer_array_value
        elif param_value.type == ParameterType.PARAMETER_DOUBLE:
            return param_value.double_value
        elif param_value.type == ParameterType.PARAMETER_DOUBLE_ARRAY:
            return param_value.double_array_value
        elif param_value.type == ParameterType.PARAMETER_BOOL:
            return param_value.bool_value
        elif param_value.type == ParameterType.PARAMETER_BOOL_ARRAY:
            return param_value.bool_array_value
        elif param_value.type == ParameterType.PARAMETER_BYTE_ARRAY:
            return param_value.byte_array_value
        else:
            return None
    @staticmethod
    def set_parameter_value(param_type:ParameterType, value)->ParameterValue:
        param_value = ParameterValue()
        if param_type == ParameterType.PARAMETER_STRING:
            param_value.string_value = value
        elif param_value == ParameterType.PARAMETER_STRING_ARRAY:
            param_value.string_array_value = value
        elif param_value == ParameterType.PARAMETER_INTEGER:
            param_value.integer_value = value
        elif param_value == ParameterType.PARAMETER_INTEGER_ARRAY:
            param_value.integer_array_value = value
        elif param_value == ParameterType.PARAMETER_DOUBLE:
            param_value.double_value = value
        elif param_value == ParameterType.PARAMETER_DOUBLE_ARRAY:
            param_value.double_array_value = value
        elif param_value == ParameterType.PARAMETER_BOOL:
            param_value.bool_value = value
        elif param_value == ParameterType.PARAMETER_BOOL_ARRAY:
            param_value.bool_array_value = value
        elif param_value == ParameterType.PARAMETER_BYTE_ARRAY:
            param_value.byte_array_value = value
        param_value.type = param_type
        return param_value
