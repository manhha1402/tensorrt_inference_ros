// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: google/type/fraction.proto
// Protobuf C++ Version: 5.27.2

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2ffraction_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2ffraction_2eproto_2epb_2eh

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
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_google_2ftype_2ffraction_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2ftype_2ffraction_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_google_2ftype_2ffraction_2eproto;
namespace google {
namespace type {
class Fraction;
struct FractionDefaultTypeInternal;
extern FractionDefaultTypeInternal _Fraction_default_instance_;
}  // namespace type
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace google {
namespace type {

// ===================================================================


// -------------------------------------------------------------------

class Fraction final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:google.type.Fraction) */ {
 public:
  inline Fraction() : Fraction(nullptr) {}
  ~Fraction() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Fraction(
      ::google::protobuf::internal::ConstantInitialized);

  inline Fraction(const Fraction& from) : Fraction(nullptr, from) {}
  inline Fraction(Fraction&& from) noexcept
      : Fraction(nullptr, std::move(from)) {}
  inline Fraction& operator=(const Fraction& from) {
    CopyFrom(from);
    return *this;
  }
  inline Fraction& operator=(Fraction&& from) noexcept {
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
  static const Fraction& default_instance() {
    return *internal_default_instance();
  }
  static inline const Fraction* internal_default_instance() {
    return reinterpret_cast<const Fraction*>(
        &_Fraction_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Fraction& a, Fraction& b) { a.Swap(&b); }
  inline void Swap(Fraction* other) {
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
  void UnsafeArenaSwap(Fraction* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Fraction* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Fraction>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Fraction& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Fraction& from) { Fraction::MergeImpl(*this, from); }

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
  void InternalSwap(Fraction* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "google.type.Fraction"; }

 protected:
  explicit Fraction(::google::protobuf::Arena* arena);
  Fraction(::google::protobuf::Arena* arena, const Fraction& from);
  Fraction(::google::protobuf::Arena* arena, Fraction&& from) noexcept
      : Fraction(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kNumeratorFieldNumber = 1,
    kDenominatorFieldNumber = 2,
  };
  // int64 numerator = 1 [json_name = "numerator"];
  void clear_numerator() ;
  ::int64_t numerator() const;
  void set_numerator(::int64_t value);

  private:
  ::int64_t _internal_numerator() const;
  void _internal_set_numerator(::int64_t value);

  public:
  // int64 denominator = 2 [json_name = "denominator"];
  void clear_denominator() ;
  ::int64_t denominator() const;
  void set_denominator(::int64_t value);

  private:
  ::int64_t _internal_denominator() const;
  void _internal_set_denominator(::int64_t value);

  public:
  // @@protoc_insertion_point(class_scope:google.type.Fraction)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      1, 2, 0,
      0, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_Fraction_default_instance_;

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
                          const Fraction& from_msg);
    ::int64_t numerator_;
    ::int64_t denominator_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_google_2ftype_2ffraction_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Fraction

// int64 numerator = 1 [json_name = "numerator"];
inline void Fraction::clear_numerator() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.numerator_ = ::int64_t{0};
}
inline ::int64_t Fraction::numerator() const {
  // @@protoc_insertion_point(field_get:google.type.Fraction.numerator)
  return _internal_numerator();
}
inline void Fraction::set_numerator(::int64_t value) {
  _internal_set_numerator(value);
  // @@protoc_insertion_point(field_set:google.type.Fraction.numerator)
}
inline ::int64_t Fraction::_internal_numerator() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.numerator_;
}
inline void Fraction::_internal_set_numerator(::int64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.numerator_ = value;
}

// int64 denominator = 2 [json_name = "denominator"];
inline void Fraction::clear_denominator() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.denominator_ = ::int64_t{0};
}
inline ::int64_t Fraction::denominator() const {
  // @@protoc_insertion_point(field_get:google.type.Fraction.denominator)
  return _internal_denominator();
}
inline void Fraction::set_denominator(::int64_t value) {
  _internal_set_denominator(value);
  // @@protoc_insertion_point(field_set:google.type.Fraction.denominator)
}
inline ::int64_t Fraction::_internal_denominator() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.denominator_;
}
inline void Fraction::_internal_set_denominator(::int64_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.denominator_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace type
}  // namespace google


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_google_2ftype_2ffraction_2eproto_2epb_2eh
