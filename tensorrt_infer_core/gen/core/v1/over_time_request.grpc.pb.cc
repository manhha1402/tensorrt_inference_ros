// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: core/v1/over_time_request.proto

#include "core/v1/over_time_request.pb.h"
#include "core/v1/over_time_request.grpc.pb.h"

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

static const char* OverTimeRequestService_method_names[] = {
  "/core.v1.OverTimeRequestService/Autocomplete",
  "/core.v1.OverTimeRequestService/Create",
  "/core.v1.OverTimeRequestService/Get",
  "/core.v1.OverTimeRequestService/List",
  "/core.v1.OverTimeRequestService/Update",
  "/core.v1.OverTimeRequestService/SoftDelete",
  "/core.v1.OverTimeRequestService/Delete",
};

std::unique_ptr< OverTimeRequestService::Stub> OverTimeRequestService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< OverTimeRequestService::Stub> stub(new OverTimeRequestService::Stub(channel, options));
  return stub;
}

OverTimeRequestService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Autocomplete_(OverTimeRequestService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Create_(OverTimeRequestService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Get_(OverTimeRequestService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_List_(OverTimeRequestService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Update_(OverTimeRequestService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SoftDelete_(OverTimeRequestService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Delete_(OverTimeRequestService_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status OverTimeRequestService::Stub::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::api::v1::AutocompleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Autocomplete_, context, request, response);
}

void OverTimeRequestService::Stub::async::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Autocomplete_, context, request, response, std::move(f));
}

void OverTimeRequestService::Stub::async::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Autocomplete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::AutocompleteResponse>* OverTimeRequestService::Stub::PrepareAsyncAutocompleteRaw(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::AutocompleteResponse, ::api::v1::AutocompleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Autocomplete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::AutocompleteResponse>* OverTimeRequestService::Stub::AsyncAutocompleteRaw(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAutocompleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OverTimeRequestService::Stub::Create(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest& request, ::core::v1::OverTimeRequest* response) {
  return ::grpc::internal::BlockingUnaryCall< ::core::v1::SaveOverTimeRequestRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Create_, context, request, response);
}

void OverTimeRequestService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest* request, ::core::v1::OverTimeRequest* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::core::v1::SaveOverTimeRequestRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, std::move(f));
}

void OverTimeRequestService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest* request, ::core::v1::OverTimeRequest* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::OverTimeRequest>* OverTimeRequestService::Stub::PrepareAsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::OverTimeRequest, ::core::v1::SaveOverTimeRequestRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Create_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::OverTimeRequest>* OverTimeRequestService::Stub::AsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OverTimeRequestService::Stub::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::core::v1::OverTimeRequest* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::GetRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Get_, context, request, response);
}

void OverTimeRequestService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::OverTimeRequest* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::GetRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, std::move(f));
}

void OverTimeRequestService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::OverTimeRequest* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::OverTimeRequest>* OverTimeRequestService::Stub::PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::OverTimeRequest, ::api::v1::GetRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Get_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::OverTimeRequest>* OverTimeRequestService::Stub::AsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OverTimeRequestService::Stub::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::core::v1::ListOverTimeRequestResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListOverTimeRequestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_List_, context, request, response);
}

void OverTimeRequestService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListOverTimeRequestResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListOverTimeRequestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, std::move(f));
}

void OverTimeRequestService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListOverTimeRequestResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListOverTimeRequestResponse>* OverTimeRequestService::Stub::PrepareAsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::ListOverTimeRequestResponse, ::api::v1::SelectRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_List_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListOverTimeRequestResponse>* OverTimeRequestService::Stub::AsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncListRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OverTimeRequestService::Stub::Update(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest& request, ::core::v1::OverTimeRequest* response) {
  return ::grpc::internal::BlockingUnaryCall< ::core::v1::SaveOverTimeRequestRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Update_, context, request, response);
}

void OverTimeRequestService::Stub::async::Update(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest* request, ::core::v1::OverTimeRequest* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::core::v1::SaveOverTimeRequestRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, std::move(f));
}

void OverTimeRequestService::Stub::async::Update(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest* request, ::core::v1::OverTimeRequest* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::OverTimeRequest>* OverTimeRequestService::Stub::PrepareAsyncUpdateRaw(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::OverTimeRequest, ::core::v1::SaveOverTimeRequestRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Update_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::OverTimeRequest>* OverTimeRequestService::Stub::AsyncUpdateRaw(::grpc::ClientContext* context, const ::core::v1::SaveOverTimeRequestRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncUpdateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OverTimeRequestService::Stub::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::api::v1::DeleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SoftDelete_, context, request, response);
}

void OverTimeRequestService::Stub::async::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SoftDelete_, context, request, response, std::move(f));
}

void OverTimeRequestService::Stub::async::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SoftDelete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* OverTimeRequestService::Stub::PrepareAsyncSoftDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::DeleteResponse, ::api::v1::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SoftDelete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* OverTimeRequestService::Stub::AsyncSoftDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSoftDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status OverTimeRequestService::Stub::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::api::v1::DeleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Delete_, context, request, response);
}

void OverTimeRequestService::Stub::async::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, std::move(f));
}

void OverTimeRequestService::Stub::async::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* OverTimeRequestService::Stub::PrepareAsyncDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::DeleteResponse, ::api::v1::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Delete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* OverTimeRequestService::Stub::AsyncDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

OverTimeRequestService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OverTimeRequestService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OverTimeRequestService::Service, ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OverTimeRequestService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::AutocompleteRequest* req,
             ::api::v1::AutocompleteResponse* resp) {
               return service->Autocomplete(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OverTimeRequestService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OverTimeRequestService::Service, ::core::v1::SaveOverTimeRequestRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OverTimeRequestService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::core::v1::SaveOverTimeRequestRequest* req,
             ::core::v1::OverTimeRequest* resp) {
               return service->Create(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OverTimeRequestService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OverTimeRequestService::Service, ::api::v1::GetRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OverTimeRequestService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::GetRequest* req,
             ::core::v1::OverTimeRequest* resp) {
               return service->Get(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OverTimeRequestService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OverTimeRequestService::Service, ::api::v1::SelectRequest, ::core::v1::ListOverTimeRequestResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OverTimeRequestService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::SelectRequest* req,
             ::core::v1::ListOverTimeRequestResponse* resp) {
               return service->List(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OverTimeRequestService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OverTimeRequestService::Service, ::core::v1::SaveOverTimeRequestRequest, ::core::v1::OverTimeRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OverTimeRequestService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::core::v1::SaveOverTimeRequestRequest* req,
             ::core::v1::OverTimeRequest* resp) {
               return service->Update(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OverTimeRequestService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OverTimeRequestService::Service, ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OverTimeRequestService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::DeleteRequest* req,
             ::api::v1::DeleteResponse* resp) {
               return service->SoftDelete(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      OverTimeRequestService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< OverTimeRequestService::Service, ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](OverTimeRequestService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::DeleteRequest* req,
             ::api::v1::DeleteResponse* resp) {
               return service->Delete(ctx, req, resp);
             }, this)));
}

OverTimeRequestService::Service::~Service() {
}

::grpc::Status OverTimeRequestService::Service::Autocomplete(::grpc::ServerContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OverTimeRequestService::Service::Create(::grpc::ServerContext* context, const ::core::v1::SaveOverTimeRequestRequest* request, ::core::v1::OverTimeRequest* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OverTimeRequestService::Service::Get(::grpc::ServerContext* context, const ::api::v1::GetRequest* request, ::core::v1::OverTimeRequest* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OverTimeRequestService::Service::List(::grpc::ServerContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListOverTimeRequestResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OverTimeRequestService::Service::Update(::grpc::ServerContext* context, const ::core::v1::SaveOverTimeRequestRequest* request, ::core::v1::OverTimeRequest* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OverTimeRequestService::Service::SoftDelete(::grpc::ServerContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status OverTimeRequestService::Service::Delete(::grpc::ServerContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace core
}  // namespace v1

