// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/geo/type/viewport.proto
// Protobuf C++ Version: 5.27.2

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fgeo_2ftype_2fviewport_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_google_2fgeo_2ftype_2fviewport_2eproto_2epb_2eh

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
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "google/type/latlng.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_google_2fgeo_2ftype_2fviewport_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fgeo_2ftype_2fviewport_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_google_2fgeo_2ftype_2fviewport_2eproto;
namespace google {
namespace geo {
namespace type {
class Viewport;
struct ViewportDefaultTypeInternal;
extern ViewportDefaultTypeInternal _Viewport_default_instance_;
}  // namespace type
}  // namespace geo
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace google {
namespace geo {
namespace type {

// ===================================================================


// -------------------------------------------------------------------

class Viewport final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:google.geo.type.Viewport) */ {
 public:
  inline Viewport() : Viewport(nullptr) {}
  ~Viewport() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Viewport(
      ::google::protobuf::internal::ConstantInitialized);

  inline Viewport(const Viewport& from) : Viewport(nullptr, from) {}
  inline Viewport(Viewport&& from) noexcept
      : Viewport(nullptr, std::move(from)) {}
  inline Viewport& operator=(const Viewport& from) {
    CopyFrom(from);
    return *this;
  }
  inline Viewport& operator=(Viewport&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Viewport& default_instance() {
    return *internal_default_instance();
  }
  static inline const Viewport* internal_default_instance() {
    return reinterpret_cast<const Viewport*>(
        &_Viewport_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Viewport& a, Viewport& b) { a.Swap(&b); }
  inline void Swap(Viewport* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Viewport* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Viewport* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Viewport>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Viewport& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Viewport& from) { Viewport::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Viewport* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "google.geo.type.Viewport"; }

 protected:
  explicit Viewport(::google::protobuf::Arena* arena);
  Viewport(::google::protobuf::Arena* arena, const Viewport& from);
  Viewport(::google::protobuf::Arena* arena, Viewport&& from) noexcept
      : Viewport(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kLowFieldNumber = 1,
    kHighFieldNumber = 2,
  };
  // .google.type.LatLng low = 1 [json_name = "low"];
  bool has_low() const;
  void clear_low() ;
  const ::google::type::LatLng& low() const;
  PROTOBUF_NODISCARD ::google::type::LatLng* release_low();
  ::google::type::LatLng* mutable_low();
  void set_allocated_low(::google::type::LatLng* value);
  void unsafe_arena_set_allocated_low(::google::type::LatLng* value);
  ::google::type::LatLng* unsafe_arena_release_low();

  private:
  const ::google::type::LatLng& _internal_low() const;
  ::google::type::LatLng* _internal_mutable_low();

  public:
  // .google.type.LatLng high = 2 [json_name = "high"];
  bool has_high() const;
  void clear_high() ;
  const ::google::type::LatLng& high() const;
  PROTOBUF_NODISCARD ::google::type::LatLng* release_high();
  ::google::type::LatLng* mutable_high();
  void set_allocated_high(::google::type::LatLng* value);
  void unsafe_arena_set_allocated_high(::google::type::LatLng* value);
  ::google::type::LatLng* unsafe_arena_release_high();

  private:
  const ::google::type::LatLng& _internal_high() const;
  ::google::type::LatLng* _internal_mutable_high();

  public:
  // @@protoc_insertion_point(class_scope:google.geo.type.Viewport)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 2,
      0, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_Viewport_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Viewport& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::type::LatLng* low_;
    ::google::type::LatLng* high_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2fgeo_2ftype_2fviewport_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Viewport

// .google.type.LatLng low = 1 [json_name = "low"];
inline bool Viewport::has_low() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.low_ != nullptr);
  return value;
}
inline const ::google::type::LatLng& Viewport::_internal_low() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::google::type::LatLng* p = _impl_.low_;
  return p != nullptr ? *p : reinterpret_cast<const ::google::type::LatLng&>(::google::type::_LatLng_default_instance_);
}
inline const ::google::type::LatLng& Viewport::low() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.geo.type.Viewport.low)
  return _internal_low();
}
inline void Viewport::unsafe_arena_set_allocated_low(::google::type::LatLng* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.low_);
  }
  _impl_.low_ = reinterpret_cast<::google::type::LatLng*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:google.geo.type.Viewport.low)
}
inline ::google::type::LatLng* Viewport::release_low() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::google::type::LatLng* released = _impl_.low_;
  _impl_.low_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::google::type::LatLng* Viewport::unsafe_arena_release_low() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:google.geo.type.Viewport.low)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::google::type::LatLng* temp = _impl_.low_;
  _impl_.low_ = nullptr;
  return temp;
}
inline ::google::type::LatLng* Viewport::_internal_mutable_low() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.low_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::google::type::LatLng>(GetArena());
    _impl_.low_ = reinterpret_cast<::google::type::LatLng*>(p);
  }
  return _impl_.low_;
}
inline ::google::type::LatLng* Viewport::mutable_low() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000001u;
  ::google::type::LatLng* _msg = _internal_mutable_low();
  // @@protoc_insertion_point(field_mutable:google.geo.type.Viewport.low)
  return _msg;
}
inline void Viewport::set_allocated_low(::google::type::LatLng* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.low_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.low_ = reinterpret_cast<::google::type::LatLng*>(value);
  // @@protoc_insertion_point(field_set_allocated:google.geo.type.Viewport.low)
}

// .google.type.LatLng high = 2 [json_name = "high"];
inline bool Viewport::has_high() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.high_ != nullptr);
  return value;
}
inline const ::google::type::LatLng& Viewport::_internal_high() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::google::type::LatLng* p = _impl_.high_;
  return p != nullptr ? *p : reinterpret_cast<const ::google::type::LatLng&>(::google::type::_LatLng_default_instance_);
}
inline const ::google::type::LatLng& Viewport::high() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:google.geo.type.Viewport.high)
  return _internal_high();
}
inline void Viewport::unsafe_arena_set_allocated_high(::google::type::LatLng* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.high_);
  }
  _impl_.high_ = reinterpret_cast<::google::type::LatLng*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:google.geo.type.Viewport.high)
}
inline ::google::type::LatLng* Viewport::release_high() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::google::type::LatLng* released = _impl_.high_;
  _impl_.high_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
  released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  if (GetArena() == nullptr) {
    delete old;
  }
#else   // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArena() != nullptr) {
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return released;
}
inline ::google::type::LatLng* Viewport::unsafe_arena_release_high() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:google.geo.type.Viewport.high)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::google::type::LatLng* temp = _impl_.high_;
  _impl_.high_ = nullptr;
  return temp;
}
inline ::google::type::LatLng* Viewport::_internal_mutable_high() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.high_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::google::type::LatLng>(GetArena());
    _impl_.high_ = reinterpret_cast<::google::type::LatLng*>(p);
  }
  return _impl_.high_;
}
inline ::google::type::LatLng* Viewport::mutable_high() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000002u;
  ::google::type::LatLng* _msg = _internal_mutable_high();
  // @@protoc_insertion_point(field_mutable:google.geo.type.Viewport.high)
  return _msg;
}
inline void Viewport::set_allocated_high(::google::type::LatLng* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.high_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.high_ = reinterpret_cast<::google::type::LatLng*>(value);
  // @@protoc_insertion_point(field_set_allocated:google.geo.type.Viewport.high)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace type
}  // namespace geo
}  // namespace google


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_google_2fgeo_2ftype_2fviewport_2eproto_2epb_2eh
