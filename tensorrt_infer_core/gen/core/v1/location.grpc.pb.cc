// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: core/v1/location.proto

#include "core/v1/location.pb.h"
#include "core/v1/location.grpc.pb.h"

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

static const char* LocationService_method_names[] = {
  "/core.v1.LocationService/Autocomplete",
  "/core.v1.LocationService/Create",
  "/core.v1.LocationService/Get",
  "/core.v1.LocationService/List",
  "/core.v1.LocationService/Update",
  "/core.v1.LocationService/SoftDelete",
  "/core.v1.LocationService/Delete",
};

std::unique_ptr< LocationService::Stub> LocationService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< LocationService::Stub> stub(new LocationService::Stub(channel, options));
  return stub;
}

LocationService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Autocomplete_(LocationService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Create_(LocationService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Get_(LocationService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_List_(LocationService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Update_(LocationService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SoftDelete_(LocationService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Delete_(LocationService_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status LocationService::Stub::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::api::v1::AutocompleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Autocomplete_, context, request, response);
}

void LocationService::Stub::async::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Autocomplete_, context, request, response, std::move(f));
}

void LocationService::Stub::async::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Autocomplete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::AutocompleteResponse>* LocationService::Stub::PrepareAsyncAutocompleteRaw(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::AutocompleteResponse, ::api::v1::AutocompleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Autocomplete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::AutocompleteResponse>* LocationService::Stub::AsyncAutocompleteRaw(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAutocompleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LocationService::Stub::Create(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest& request, ::core::v1::Location* response) {
  return ::grpc::internal::BlockingUnaryCall< ::core::v1::SaveLocationRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Create_, context, request, response);
}

void LocationService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest* request, ::core::v1::Location* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::core::v1::SaveLocationRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, std::move(f));
}

void LocationService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest* request, ::core::v1::Location* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Location>* LocationService::Stub::PrepareAsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::Location, ::core::v1::SaveLocationRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Create_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Location>* LocationService::Stub::AsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LocationService::Stub::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::core::v1::Location* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::GetRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Get_, context, request, response);
}

void LocationService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::Location* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::GetRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, std::move(f));
}

void LocationService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::Location* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Location>* LocationService::Stub::PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::Location, ::api::v1::GetRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Get_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Location>* LocationService::Stub::AsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LocationService::Stub::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::core::v1::ListLocationResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListLocationResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_List_, context, request, response);
}

void LocationService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListLocationResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListLocationResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, std::move(f));
}

void LocationService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListLocationResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListLocationResponse>* LocationService::Stub::PrepareAsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::ListLocationResponse, ::api::v1::SelectRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_List_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListLocationResponse>* LocationService::Stub::AsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncListRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LocationService::Stub::Update(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest& request, ::core::v1::Location* response) {
  return ::grpc::internal::BlockingUnaryCall< ::core::v1::SaveLocationRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Update_, context, request, response);
}

void LocationService::Stub::async::Update(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest* request, ::core::v1::Location* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::core::v1::SaveLocationRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, std::move(f));
}

void LocationService::Stub::async::Update(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest* request, ::core::v1::Location* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Location>* LocationService::Stub::PrepareAsyncUpdateRaw(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::Location, ::core::v1::SaveLocationRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Update_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Location>* LocationService::Stub::AsyncUpdateRaw(::grpc::ClientContext* context, const ::core::v1::SaveLocationRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncUpdateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LocationService::Stub::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::api::v1::DeleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SoftDelete_, context, request, response);
}

void LocationService::Stub::async::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SoftDelete_, context, request, response, std::move(f));
}

void LocationService::Stub::async::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SoftDelete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* LocationService::Stub::PrepareAsyncSoftDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::DeleteResponse, ::api::v1::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SoftDelete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* LocationService::Stub::AsyncSoftDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSoftDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status LocationService::Stub::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::api::v1::DeleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Delete_, context, request, response);
}

void LocationService::Stub::async::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, std::move(f));
}

void LocationService::Stub::async::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* LocationService::Stub::PrepareAsyncDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::DeleteResponse, ::api::v1::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Delete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* LocationService::Stub::AsyncDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

LocationService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LocationService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LocationService::Service, ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::AutocompleteRequest* req,
             ::api::v1::AutocompleteResponse* resp) {
               return service->Autocomplete(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LocationService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LocationService::Service, ::core::v1::SaveLocationRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::core::v1::SaveLocationRequest* req,
             ::core::v1::Location* resp) {
               return service->Create(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LocationService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LocationService::Service, ::api::v1::GetRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::GetRequest* req,
             ::core::v1::Location* resp) {
               return service->Get(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LocationService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LocationService::Service, ::api::v1::SelectRequest, ::core::v1::ListLocationResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::SelectRequest* req,
             ::core::v1::ListLocationResponse* resp) {
               return service->List(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LocationService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LocationService::Service, ::core::v1::SaveLocationRequest, ::core::v1::Location, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::core::v1::SaveLocationRequest* req,
             ::core::v1::Location* resp) {
               return service->Update(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LocationService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LocationService::Service, ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::DeleteRequest* req,
             ::api::v1::DeleteResponse* resp) {
               return service->SoftDelete(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      LocationService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< LocationService::Service, ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](LocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::DeleteRequest* req,
             ::api::v1::DeleteResponse* resp) {
               return service->Delete(ctx, req, resp);
             }, this)));
}

LocationService::Service::~Service() {
}

::grpc::Status LocationService::Service::Autocomplete(::grpc::ServerContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LocationService::Service::Create(::grpc::ServerContext* context, const ::core::v1::SaveLocationRequest* request, ::core::v1::Location* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LocationService::Service::Get(::grpc::ServerContext* context, const ::api::v1::GetRequest* request, ::core::v1::Location* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LocationService::Service::List(::grpc::ServerContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListLocationResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LocationService::Service::Update(::grpc::ServerContext* context, const ::core::v1::SaveLocationRequest* request, ::core::v1::Location* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LocationService::Service::SoftDelete(::grpc::ServerContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status LocationService::Service::Delete(::grpc::ServerContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace core
}  // namespace v1

