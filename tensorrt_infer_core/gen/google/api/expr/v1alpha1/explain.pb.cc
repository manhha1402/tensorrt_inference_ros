// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/api/expr/v1alpha1/explain.proto
// Protobuf C++ Version: 5.27.2

#include "google/api/expr/v1alpha1/explain.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace google {
namespace api {
namespace expr {
namespace v1alpha1 {

inline constexpr Explain_ExprStep::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : id_{::int64_t{0}},
        value_index_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Explain_ExprStep::Explain_ExprStep(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct Explain_ExprStepDefaultTypeInternal {
  PROTOBUF_CONSTEXPR Explain_ExprStepDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~Explain_ExprStepDefaultTypeInternal() {}
  union {
    Explain_ExprStep _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Explain_ExprStepDefaultTypeInternal _Explain_ExprStep_default_instance_;

inline constexpr Explain::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : values_{},
        expr_steps_{},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR Explain::Explain(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ExplainDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ExplainDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ExplainDefaultTypeInternal() {}
  union {
    Explain _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ExplainDefaultTypeInternal _Explain_default_instance_;
}  // namespace v1alpha1
}  // namespace expr
}  // namespace api
}  // namespace google
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto = nullptr;
const ::uint32_t
    TableStruct_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::google::api::expr::v1alpha1::Explain_ExprStep, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::google::api::expr::v1alpha1::Explain_ExprStep, _impl_.id_),
        PROTOBUF_FIELD_OFFSET(::google::api::expr::v1alpha1::Explain_ExprStep, _impl_.value_index_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::google::api::expr::v1alpha1::Explain, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::google::api::expr::v1alpha1::Explain, _impl_.values_),
        PROTOBUF_FIELD_OFFSET(::google::api::expr::v1alpha1::Explain, _impl_.expr_steps_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::google::api::expr::v1alpha1::Explain_ExprStep)},
        {10, -1, -1, sizeof(::google::api::expr::v1alpha1::Explain)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::google::api::expr::v1alpha1::_Explain_ExprStep_default_instance_._instance,
    &::google::api::expr::v1alpha1::_Explain_default_instance_._instance,
};
const char descriptor_table_protodef_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n&google/api/expr/v1alpha1/explain.proto"
    "\022\030google.api.expr.v1alpha1\032$google/api/e"
    "xpr/v1alpha1/value.proto\"\316\001\n\007Explain\0227\n\006"
    "values\030\001 \003(\0132\037.google.api.expr.v1alpha1."
    "ValueR\006values\022I\n\nexpr_steps\030\002 \003(\0132*.goog"
    "le.api.expr.v1alpha1.Explain.ExprStepR\te"
    "xprSteps\032;\n\010ExprStep\022\016\n\002id\030\001 \001(\003R\002id\022\037\n\013"
    "value_index\030\002 \001(\005R\nvalueIndex:\002\030\001Bo\n\034com"
    ".google.api.expr.v1alpha1B\014ExplainProtoP"
    "\001Z<google.golang.org/genproto/googleapis"
    "/api/expr/v1alpha1;expr\370\001\001b\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto_deps[1] =
    {
        &::descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fvalue_2eproto,
};
static ::absl::once_flag descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto = {
    false,
    false,
    434,
    descriptor_table_protodef_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto,
    "google/api/expr/v1alpha1/explain.proto",
    &descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto_once,
    descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto_deps,
    1,
    2,
    schemas,
    file_default_instances,
    TableStruct_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto::offsets,
    file_level_enum_descriptors_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto,
    file_level_service_descriptors_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto,
};
namespace google {
namespace api {
namespace expr {
namespace v1alpha1 {
// ===================================================================

class Explain_ExprStep::_Internal {
 public:
};

Explain_ExprStep::Explain_ExprStep(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:google.api.expr.v1alpha1.Explain.ExprStep)
}
Explain_ExprStep::Explain_ExprStep(
    ::google::protobuf::Arena* arena, const Explain_ExprStep& from)
    : Explain_ExprStep(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE Explain_ExprStep::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void Explain_ExprStep::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, id_),
           0,
           offsetof(Impl_, value_index_) -
               offsetof(Impl_, id_) +
               sizeof(Impl_::value_index_));
}
Explain_ExprStep::~Explain_ExprStep() {
  // @@protoc_insertion_point(destructor:google.api.expr.v1alpha1.Explain.ExprStep)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Explain_ExprStep::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Explain_ExprStep::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(Explain_ExprStep, _impl_._cached_size_),
              false,
          },
          &Explain_ExprStep::MergeImpl,
          &Explain_ExprStep::kDescriptorMethods,
          &descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 0, 2> Explain_ExprStep::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_Explain_ExprStep_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::google::api::expr::v1alpha1::Explain_ExprStep>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // int32 value_index = 2 [json_name = "valueIndex"];
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Explain_ExprStep, _impl_.value_index_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(Explain_ExprStep, _impl_.value_index_)}},
    // int64 id = 1 [json_name = "id"];
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(Explain_ExprStep, _impl_.id_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(Explain_ExprStep, _impl_.id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // int64 id = 1 [json_name = "id"];
    {PROTOBUF_FIELD_OFFSET(Explain_ExprStep, _impl_.id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt64)},
    // int32 value_index = 2 [json_name = "valueIndex"];
    {PROTOBUF_FIELD_OFFSET(Explain_ExprStep, _impl_.value_index_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void Explain_ExprStep::Clear() {
// @@protoc_insertion_point(message_clear_start:google.api.expr.v1alpha1.Explain.ExprStep)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.id_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.value_index_) -
      reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.value_index_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Explain_ExprStep::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:google.api.expr.v1alpha1.Explain.ExprStep)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // int64 id = 1 [json_name = "id"];
  if (this->_internal_id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt64ToArrayWithField<1>(
            stream, this->_internal_id(), target);
  }

  // int32 value_index = 2 [json_name = "valueIndex"];
  if (this->_internal_value_index() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<2>(
            stream, this->_internal_value_index(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.api.expr.v1alpha1.Explain.ExprStep)
  return target;
}

::size_t Explain_ExprStep::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:google.api.expr.v1alpha1.Explain.ExprStep)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // int64 id = 1 [json_name = "id"];
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(
        this->_internal_id());
  }

  // int32 value_index = 2 [json_name = "valueIndex"];
  if (this->_internal_value_index() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_value_index());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Explain_ExprStep::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Explain_ExprStep*>(&to_msg);
  auto& from = static_cast<const Explain_ExprStep&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:google.api.expr.v1alpha1.Explain.ExprStep)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_id() != 0) {
    _this->_impl_.id_ = from._impl_.id_;
  }
  if (from._internal_value_index() != 0) {
    _this->_impl_.value_index_ = from._impl_.value_index_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Explain_ExprStep::CopyFrom(const Explain_ExprStep& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.api.expr.v1alpha1.Explain.ExprStep)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Explain_ExprStep::InternalSwap(Explain_ExprStep* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Explain_ExprStep, _impl_.value_index_)
      + sizeof(Explain_ExprStep::_impl_.value_index_)
      - PROTOBUF_FIELD_OFFSET(Explain_ExprStep, _impl_.id_)>(
          reinterpret_cast<char*>(&_impl_.id_),
          reinterpret_cast<char*>(&other->_impl_.id_));
}

::google::protobuf::Metadata Explain_ExprStep::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class Explain::_Internal {
 public:
};

void Explain::clear_values() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.values_.Clear();
}
Explain::Explain(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:google.api.expr.v1alpha1.Explain)
}
inline PROTOBUF_NDEBUG_INLINE Explain::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::google::api::expr::v1alpha1::Explain& from_msg)
      : values_{visibility, arena, from.values_},
        expr_steps_{visibility, arena, from.expr_steps_},
        _cached_size_{0} {}

Explain::Explain(
    ::google::protobuf::Arena* arena,
    const Explain& from)
    : ::google::protobuf::Message(arena) {
  Explain* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:google.api.expr.v1alpha1.Explain)
}
inline PROTOBUF_NDEBUG_INLINE Explain::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : values_{visibility, arena},
        expr_steps_{visibility, arena},
        _cached_size_{0} {}

inline void Explain::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
Explain::~Explain() {
  // @@protoc_insertion_point(destructor:google.api.expr.v1alpha1.Explain)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void Explain::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
Explain::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(Explain, _impl_._cached_size_),
              false,
          },
          &Explain::MergeImpl,
          &Explain::kDescriptorMethods,
          &descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 2, 0, 2> Explain::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    2,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_Explain_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::google::api::expr::v1alpha1::Explain>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // repeated .google.api.expr.v1alpha1.Explain.ExprStep expr_steps = 2 [json_name = "exprSteps"];
    {::_pbi::TcParser::FastMtR1,
     {18, 63, 1, PROTOBUF_FIELD_OFFSET(Explain, _impl_.expr_steps_)}},
    // repeated .google.api.expr.v1alpha1.Value values = 1 [json_name = "values"];
    {::_pbi::TcParser::FastMtR1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(Explain, _impl_.values_)}},
  }}, {{
    65535, 65535
  }}, {{
    // repeated .google.api.expr.v1alpha1.Value values = 1 [json_name = "values"];
    {PROTOBUF_FIELD_OFFSET(Explain, _impl_.values_), 0, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated .google.api.expr.v1alpha1.Explain.ExprStep expr_steps = 2 [json_name = "exprSteps"];
    {PROTOBUF_FIELD_OFFSET(Explain, _impl_.expr_steps_), 0, 1,
    (0 | ::_fl::kFcRepeated | ::_fl::kMessage | ::_fl::kTvTable)},
  }}, {{
    {::_pbi::TcParser::GetTable<::google::api::expr::v1alpha1::Value>()},
    {::_pbi::TcParser::GetTable<::google::api::expr::v1alpha1::Explain_ExprStep>()},
  }}, {{
  }},
};

PROTOBUF_NOINLINE void Explain::Clear() {
// @@protoc_insertion_point(message_clear_start:google.api.expr.v1alpha1.Explain)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.values_.Clear();
  _impl_.expr_steps_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* Explain::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:google.api.expr.v1alpha1.Explain)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // repeated .google.api.expr.v1alpha1.Value values = 1 [json_name = "values"];
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_values_size());
       i < n; i++) {
    const auto& repfield = this->_internal_values().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            1, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  // repeated .google.api.expr.v1alpha1.Explain.ExprStep expr_steps = 2 [json_name = "exprSteps"];
  for (unsigned i = 0, n = static_cast<unsigned>(
                           this->_internal_expr_steps_size());
       i < n; i++) {
    const auto& repfield = this->_internal_expr_steps().Get(i);
    target =
        ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
            2, repfield, repfield.GetCachedSize(),
            target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:google.api.expr.v1alpha1.Explain)
  return target;
}

::size_t Explain::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:google.api.expr.v1alpha1.Explain)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // repeated .google.api.expr.v1alpha1.Value values = 1 [json_name = "values"];
  total_size += 1UL * this->_internal_values_size();
  for (const auto& msg : this->_internal_values()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  // repeated .google.api.expr.v1alpha1.Explain.ExprStep expr_steps = 2 [json_name = "exprSteps"];
  total_size += 1UL * this->_internal_expr_steps_size();
  for (const auto& msg : this->_internal_expr_steps()) {
    total_size += ::google::protobuf::internal::WireFormatLite::MessageSize(msg);
  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void Explain::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Explain*>(&to_msg);
  auto& from = static_cast<const Explain&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:google.api.expr.v1alpha1.Explain)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_values()->MergeFrom(
      from._internal_values());
  _this->_internal_mutable_expr_steps()->MergeFrom(
      from._internal_expr_steps());
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Explain::CopyFrom(const Explain& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:google.api.expr.v1alpha1.Explain)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Explain::InternalSwap(Explain* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.values_.InternalSwap(&other->_impl_.values_);
  _impl_.expr_steps_.InternalSwap(&other->_impl_.expr_steps_);
}

::google::protobuf::Metadata Explain::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace v1alpha1
}  // namespace expr
}  // namespace api
}  // namespace google
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_google_2fapi_2fexpr_2fv1alpha1_2fexplain_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
