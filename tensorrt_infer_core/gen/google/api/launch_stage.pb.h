// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/api/launch_stage.proto
// Protobuf C++ Version: 5.27.2

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fapi_2flaunch_5fstage_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_google_2fapi_2flaunch_5fstage_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5027002
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_google_2fapi_2flaunch_5fstage_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fapi_2flaunch_5fstage_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_google_2fapi_2flaunch_5fstage_2eproto;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace google {
namespace api {
enum LaunchStage : int {
  LAUNCH_STAGE_UNSPECIFIED = 0,
  UNIMPLEMENTED = 6,
  PRELAUNCH = 7,
  EARLY_ACCESS = 1,
  ALPHA = 2,
  BETA = 3,
  GA = 4,
  DEPRECATED = 5,
  LaunchStage_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  LaunchStage_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool LaunchStage_IsValid(int value);
extern const uint32_t LaunchStage_internal_data_[];
constexpr LaunchStage LaunchStage_MIN = static_cast<LaunchStage>(0);
constexpr LaunchStage LaunchStage_MAX = static_cast<LaunchStage>(7);
constexpr int LaunchStage_ARRAYSIZE = 7 + 1;
const ::google::protobuf::EnumDescriptor*
LaunchStage_descriptor();
template <typename T>
const std::string& LaunchStage_Name(T value) {
  static_assert(std::is_same<T, LaunchStage>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to LaunchStage_Name().");
  return LaunchStage_Name(static_cast<LaunchStage>(value));
}
template <>
inline const std::string& LaunchStage_Name(LaunchStage value) {
  return ::google::protobuf::internal::NameOfDenseEnum<LaunchStage_descriptor,
                                                 0, 7>(
      static_cast<int>(value));
}
inline bool LaunchStage_Parse(absl::string_view name, LaunchStage* value) {
  return ::google::protobuf::internal::ParseNamedEnum<LaunchStage>(
      LaunchStage_descriptor(), name, value);
}

// ===================================================================



// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace api
}  // namespace google


namespace google {
namespace protobuf {

template <>
struct is_proto_enum<::google::api::LaunchStage> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::google::api::LaunchStage>() {
  return ::google::api::LaunchStage_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_google_2fapi_2flaunch_5fstage_2eproto_2epb_2eh
