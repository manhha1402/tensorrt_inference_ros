// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: core/v1/camera_config.proto

#include "core/v1/camera_config.pb.h"
#include "core/v1/camera_config.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace core {
namespace v1 {

static const char* CameraConfigService_method_names[] = {
  "/core.v1.CameraConfigService/Create",
  "/core.v1.CameraConfigService/Get",
  "/core.v1.CameraConfigService/List",
};

std::unique_ptr< CameraConfigService::Stub> CameraConfigService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< CameraConfigService::Stub> stub(new CameraConfigService::Stub(channel, options));
  return stub;
}

CameraConfigService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Create_(CameraConfigService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Get_(CameraConfigService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_List_(CameraConfigService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status CameraConfigService::Stub::Create(::grpc::ClientContext* context, const ::core::v1::SaveCameraConfigRequest& request, ::core::v1::CameraConfig* response) {
  return ::grpc::internal::BlockingUnaryCall< ::core::v1::SaveCameraConfigRequest, ::core::v1::CameraConfig, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Create_, context, request, response);
}

void CameraConfigService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveCameraConfigRequest* request, ::core::v1::CameraConfig* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::core::v1::SaveCameraConfigRequest, ::core::v1::CameraConfig, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, std::move(f));
}

void CameraConfigService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveCameraConfigRequest* request, ::core::v1::CameraConfig* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::CameraConfig>* CameraConfigService::Stub::PrepareAsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveCameraConfigRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::CameraConfig, ::core::v1::SaveCameraConfigRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Create_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::CameraConfig>* CameraConfigService::Stub::AsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveCameraConfigRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status CameraConfigService::Stub::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::core::v1::CameraConfig* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::GetRequest, ::core::v1::CameraConfig, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Get_, context, request, response);
}

void CameraConfigService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::CameraConfig* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::GetRequest, ::core::v1::CameraConfig, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, std::move(f));
}

void CameraConfigService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::CameraConfig* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::CameraConfig>* CameraConfigService::Stub::PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::CameraConfig, ::api::v1::GetRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Get_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::CameraConfig>* CameraConfigService::Stub::AsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status CameraConfigService::Stub::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::core::v1::ListCameraConfigResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListCameraConfigResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_List_, context, request, response);
}

void CameraConfigService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListCameraConfigResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListCameraConfigResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, std::move(f));
}

void CameraConfigService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListCameraConfigResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListCameraConfigResponse>* CameraConfigService::Stub::PrepareAsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::ListCameraConfigResponse, ::api::v1::SelectRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_List_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListCameraConfigResponse>* CameraConfigService::Stub::AsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncListRaw(context, request, cq);
  result->StartCall();
  return result;
}

CameraConfigService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      CameraConfigService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< CameraConfigService::Service, ::core::v1::SaveCameraConfigRequest, ::core::v1::CameraConfig, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](CameraConfigService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::core::v1::SaveCameraConfigRequest* req,
             ::core::v1::CameraConfig* resp) {
               return service->Create(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      CameraConfigService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< CameraConfigService::Service, ::api::v1::GetRequest, ::core::v1::CameraConfig, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](CameraConfigService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::GetRequest* req,
             ::core::v1::CameraConfig* resp) {
               return service->Get(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      CameraConfigService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< CameraConfigService::Service, ::api::v1::SelectRequest, ::core::v1::ListCameraConfigResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](CameraConfigService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::SelectRequest* req,
             ::core::v1::ListCameraConfigResponse* resp) {
               return service->List(ctx, req, resp);
             }, this)));
}

CameraConfigService::Service::~Service() {
}

::grpc::Status CameraConfigService::Service::Create(::grpc::ServerContext* context, const ::core::v1::SaveCameraConfigRequest* request, ::core::v1::CameraConfig* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status CameraConfigService::Service::Get(::grpc::ServerContext* context, const ::api::v1::GetRequest* request, ::core::v1::CameraConfig* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status CameraConfigService::Service::List(::grpc::ServerContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListCameraConfigResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace core
}  // namespace v1

