// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: core/v1/bank.proto

#include "core/v1/bank.pb.h"
#include "core/v1/bank.grpc.pb.h"

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

static const char* BankService_method_names[] = {
  "/core.v1.BankService/Autocomplete",
  "/core.v1.BankService/Create",
  "/core.v1.BankService/Get",
  "/core.v1.BankService/List",
  "/core.v1.BankService/Update",
  "/core.v1.BankService/SoftDelete",
  "/core.v1.BankService/Delete",
};

std::unique_ptr< BankService::Stub> BankService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< BankService::Stub> stub(new BankService::Stub(channel, options));
  return stub;
}

BankService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Autocomplete_(BankService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Create_(BankService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Get_(BankService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_List_(BankService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Update_(BankService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SoftDelete_(BankService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_Delete_(BankService_method_names[6], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status BankService::Stub::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::api::v1::AutocompleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Autocomplete_, context, request, response);
}

void BankService::Stub::async::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Autocomplete_, context, request, response, std::move(f));
}

void BankService::Stub::async::Autocomplete(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Autocomplete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::AutocompleteResponse>* BankService::Stub::PrepareAsyncAutocompleteRaw(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::AutocompleteResponse, ::api::v1::AutocompleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Autocomplete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::AutocompleteResponse>* BankService::Stub::AsyncAutocompleteRaw(::grpc::ClientContext* context, const ::api::v1::AutocompleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAutocompleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BankService::Stub::Create(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest& request, ::core::v1::Bank* response) {
  return ::grpc::internal::BlockingUnaryCall< ::core::v1::SaveBankRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Create_, context, request, response);
}

void BankService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest* request, ::core::v1::Bank* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::core::v1::SaveBankRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, std::move(f));
}

void BankService::Stub::async::Create(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest* request, ::core::v1::Bank* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Create_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Bank>* BankService::Stub::PrepareAsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::Bank, ::core::v1::SaveBankRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Create_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Bank>* BankService::Stub::AsyncCreateRaw(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BankService::Stub::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::core::v1::Bank* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::GetRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Get_, context, request, response);
}

void BankService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::Bank* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::GetRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, std::move(f));
}

void BankService::Stub::async::Get(::grpc::ClientContext* context, const ::api::v1::GetRequest* request, ::core::v1::Bank* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Get_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Bank>* BankService::Stub::PrepareAsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::Bank, ::api::v1::GetRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Get_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Bank>* BankService::Stub::AsyncGetRaw(::grpc::ClientContext* context, const ::api::v1::GetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BankService::Stub::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::core::v1::ListBankResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListBankResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_List_, context, request, response);
}

void BankService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListBankResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::SelectRequest, ::core::v1::ListBankResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, std::move(f));
}

void BankService::Stub::async::List(::grpc::ClientContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListBankResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_List_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListBankResponse>* BankService::Stub::PrepareAsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::ListBankResponse, ::api::v1::SelectRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_List_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::ListBankResponse>* BankService::Stub::AsyncListRaw(::grpc::ClientContext* context, const ::api::v1::SelectRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncListRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BankService::Stub::Update(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest& request, ::core::v1::Bank* response) {
  return ::grpc::internal::BlockingUnaryCall< ::core::v1::SaveBankRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Update_, context, request, response);
}

void BankService::Stub::async::Update(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest* request, ::core::v1::Bank* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::core::v1::SaveBankRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, std::move(f));
}

void BankService::Stub::async::Update(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest* request, ::core::v1::Bank* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Update_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Bank>* BankService::Stub::PrepareAsyncUpdateRaw(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::core::v1::Bank, ::core::v1::SaveBankRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Update_, context, request);
}

::grpc::ClientAsyncResponseReader< ::core::v1::Bank>* BankService::Stub::AsyncUpdateRaw(::grpc::ClientContext* context, const ::core::v1::SaveBankRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncUpdateRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BankService::Stub::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::api::v1::DeleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SoftDelete_, context, request, response);
}

void BankService::Stub::async::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SoftDelete_, context, request, response, std::move(f));
}

void BankService::Stub::async::SoftDelete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SoftDelete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* BankService::Stub::PrepareAsyncSoftDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::DeleteResponse, ::api::v1::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SoftDelete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* BankService::Stub::AsyncSoftDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSoftDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status BankService::Stub::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::api::v1::DeleteResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Delete_, context, request, response);
}

void BankService::Stub::async::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, std::move(f));
}

void BankService::Stub::async::Delete(::grpc::ClientContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Delete_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* BankService::Stub::PrepareAsyncDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::api::v1::DeleteResponse, ::api::v1::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Delete_, context, request);
}

::grpc::ClientAsyncResponseReader< ::api::v1::DeleteResponse>* BankService::Stub::AsyncDeleteRaw(::grpc::ClientContext* context, const ::api::v1::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteRaw(context, request, cq);
  result->StartCall();
  return result;
}

BankService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BankService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BankService::Service, ::api::v1::AutocompleteRequest, ::api::v1::AutocompleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BankService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::AutocompleteRequest* req,
             ::api::v1::AutocompleteResponse* resp) {
               return service->Autocomplete(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BankService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BankService::Service, ::core::v1::SaveBankRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BankService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::core::v1::SaveBankRequest* req,
             ::core::v1::Bank* resp) {
               return service->Create(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BankService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BankService::Service, ::api::v1::GetRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BankService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::GetRequest* req,
             ::core::v1::Bank* resp) {
               return service->Get(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BankService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BankService::Service, ::api::v1::SelectRequest, ::core::v1::ListBankResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BankService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::SelectRequest* req,
             ::core::v1::ListBankResponse* resp) {
               return service->List(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BankService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BankService::Service, ::core::v1::SaveBankRequest, ::core::v1::Bank, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BankService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::core::v1::SaveBankRequest* req,
             ::core::v1::Bank* resp) {
               return service->Update(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BankService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BankService::Service, ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BankService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::DeleteRequest* req,
             ::api::v1::DeleteResponse* resp) {
               return service->SoftDelete(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      BankService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< BankService::Service, ::api::v1::DeleteRequest, ::api::v1::DeleteResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](BankService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::api::v1::DeleteRequest* req,
             ::api::v1::DeleteResponse* resp) {
               return service->Delete(ctx, req, resp);
             }, this)));
}

BankService::Service::~Service() {
}

::grpc::Status BankService::Service::Autocomplete(::grpc::ServerContext* context, const ::api::v1::AutocompleteRequest* request, ::api::v1::AutocompleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BankService::Service::Create(::grpc::ServerContext* context, const ::core::v1::SaveBankRequest* request, ::core::v1::Bank* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BankService::Service::Get(::grpc::ServerContext* context, const ::api::v1::GetRequest* request, ::core::v1::Bank* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BankService::Service::List(::grpc::ServerContext* context, const ::api::v1::SelectRequest* request, ::core::v1::ListBankResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BankService::Service::Update(::grpc::ServerContext* context, const ::core::v1::SaveBankRequest* request, ::core::v1::Bank* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BankService::Service::SoftDelete(::grpc::ServerContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status BankService::Service::Delete(::grpc::ServerContext* context, const ::api::v1::DeleteRequest* request, ::api::v1::DeleteResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace core
}  // namespace v1

