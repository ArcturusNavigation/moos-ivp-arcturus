// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gateway.proto

#include "gateway.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace moos {
namespace gateway {
class FromGatewayDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<FromGateway>
      _instance;
} _FromGateway_default_instance_;
class ToGatewayDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ToGateway>
      _instance;
} _ToGateway_default_instance_;
}  // namespace gateway
}  // namespace moos
namespace protobuf_gateway_2eproto {
static void InitDefaultsFromGateway() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::moos::gateway::_FromGateway_default_instance_;
    new (ptr) ::moos::gateway::FromGateway();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::moos::gateway::FromGateway::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_FromGateway =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsFromGateway}, {}};

static void InitDefaultsToGateway() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::moos::gateway::_ToGateway_default_instance_;
    new (ptr) ::moos::gateway::ToGateway();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::moos::gateway::ToGateway::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ToGateway =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsToGateway}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_FromGateway.base);
  ::google::protobuf::internal::InitSCC(&scc_info_ToGateway.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::FromGateway, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::FromGateway, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::FromGateway, gateway_time_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::FromGateway, gateway_key_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::FromGateway, gateway_string_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::FromGateway, gateway_double_),
  2,
  0,
  1,
  3,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::ToGateway, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::ToGateway, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::ToGateway, client_time_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::ToGateway, client_key_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::ToGateway, client_string_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::moos::gateway::ToGateway, client_double_),
  2,
  0,
  1,
  3,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, sizeof(::moos::gateway::FromGateway)},
  { 13, 22, sizeof(::moos::gateway::ToGateway)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::moos::gateway::_FromGateway_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::moos::gateway::_ToGateway_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "gateway.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rgateway.proto\022\014moos.gateway\"h\n\013FromGat"
      "eway\022\024\n\014gateway_time\030\001 \001(\001\022\023\n\013gateway_ke"
      "y\030\002 \001(\t\022\026\n\016gateway_string\030\003 \001(\t\022\026\n\016gatew"
      "ay_double\030\004 \001(\001\"b\n\tToGateway\022\023\n\013client_t"
      "ime\030\001 \001(\001\022\022\n\nclient_key\030\002 \001(\t\022\025\n\rclient_"
      "string\030\003 \001(\t\022\025\n\rclient_double\030\004 \001(\001"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 235);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "gateway.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_gateway_2eproto
namespace moos {
namespace gateway {

// ===================================================================

void FromGateway::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int FromGateway::kGatewayTimeFieldNumber;
const int FromGateway::kGatewayKeyFieldNumber;
const int FromGateway::kGatewayStringFieldNumber;
const int FromGateway::kGatewayDoubleFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

FromGateway::FromGateway()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_gateway_2eproto::scc_info_FromGateway.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:moos.gateway.FromGateway)
}
FromGateway::FromGateway(const FromGateway& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  gateway_key_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_gateway_key()) {
    gateway_key_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.gateway_key_);
  }
  gateway_string_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_gateway_string()) {
    gateway_string_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.gateway_string_);
  }
  ::memcpy(&gateway_time_, &from.gateway_time_,
    static_cast<size_t>(reinterpret_cast<char*>(&gateway_double_) -
    reinterpret_cast<char*>(&gateway_time_)) + sizeof(gateway_double_));
  // @@protoc_insertion_point(copy_constructor:moos.gateway.FromGateway)
}

void FromGateway::SharedCtor() {
  gateway_key_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  gateway_string_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&gateway_time_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&gateway_double_) -
      reinterpret_cast<char*>(&gateway_time_)) + sizeof(gateway_double_));
}

FromGateway::~FromGateway() {
  // @@protoc_insertion_point(destructor:moos.gateway.FromGateway)
  SharedDtor();
}

void FromGateway::SharedDtor() {
  gateway_key_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  gateway_string_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void FromGateway::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* FromGateway::descriptor() {
  ::protobuf_gateway_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_gateway_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const FromGateway& FromGateway::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_gateway_2eproto::scc_info_FromGateway.base);
  return *internal_default_instance();
}


void FromGateway::Clear() {
// @@protoc_insertion_point(message_clear_start:moos.gateway.FromGateway)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      gateway_key_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      gateway_string_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 12u) {
    ::memset(&gateway_time_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&gateway_double_) -
        reinterpret_cast<char*>(&gateway_time_)) + sizeof(gateway_double_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool FromGateway::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:moos.gateway.FromGateway)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double gateway_time = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {
          set_has_gateway_time();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &gateway_time_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string gateway_key = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_gateway_key()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->gateway_key().data(), static_cast<int>(this->gateway_key().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "moos.gateway.FromGateway.gateway_key");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string gateway_string = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_gateway_string()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->gateway_string().data(), static_cast<int>(this->gateway_string().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "moos.gateway.FromGateway.gateway_string");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double gateway_double = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(33u /* 33 & 0xFF */)) {
          set_has_gateway_double();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &gateway_double_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:moos.gateway.FromGateway)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:moos.gateway.FromGateway)
  return false;
#undef DO_
}

void FromGateway::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:moos.gateway.FromGateway)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional double gateway_time = 1;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->gateway_time(), output);
  }

  // optional string gateway_key = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->gateway_key().data(), static_cast<int>(this->gateway_key().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.FromGateway.gateway_key");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->gateway_key(), output);
  }

  // optional string gateway_string = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->gateway_string().data(), static_cast<int>(this->gateway_string().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.FromGateway.gateway_string");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->gateway_string(), output);
  }

  // optional double gateway_double = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->gateway_double(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:moos.gateway.FromGateway)
}

::google::protobuf::uint8* FromGateway::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:moos.gateway.FromGateway)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional double gateway_time = 1;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->gateway_time(), target);
  }

  // optional string gateway_key = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->gateway_key().data(), static_cast<int>(this->gateway_key().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.FromGateway.gateway_key");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->gateway_key(), target);
  }

  // optional string gateway_string = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->gateway_string().data(), static_cast<int>(this->gateway_string().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.FromGateway.gateway_string");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->gateway_string(), target);
  }

  // optional double gateway_double = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->gateway_double(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:moos.gateway.FromGateway)
  return target;
}

size_t FromGateway::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:moos.gateway.FromGateway)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 15u) {
    // optional string gateway_key = 2;
    if (has_gateway_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->gateway_key());
    }

    // optional string gateway_string = 3;
    if (has_gateway_string()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->gateway_string());
    }

    // optional double gateway_time = 1;
    if (has_gateway_time()) {
      total_size += 1 + 8;
    }

    // optional double gateway_double = 4;
    if (has_gateway_double()) {
      total_size += 1 + 8;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void FromGateway::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:moos.gateway.FromGateway)
  GOOGLE_DCHECK_NE(&from, this);
  const FromGateway* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const FromGateway>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:moos.gateway.FromGateway)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:moos.gateway.FromGateway)
    MergeFrom(*source);
  }
}

void FromGateway::MergeFrom(const FromGateway& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:moos.gateway.FromGateway)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_gateway_key();
      gateway_key_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.gateway_key_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_gateway_string();
      gateway_string_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.gateway_string_);
    }
    if (cached_has_bits & 0x00000004u) {
      gateway_time_ = from.gateway_time_;
    }
    if (cached_has_bits & 0x00000008u) {
      gateway_double_ = from.gateway_double_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void FromGateway::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:moos.gateway.FromGateway)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FromGateway::CopyFrom(const FromGateway& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:moos.gateway.FromGateway)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FromGateway::IsInitialized() const {
  return true;
}

void FromGateway::Swap(FromGateway* other) {
  if (other == this) return;
  InternalSwap(other);
}
void FromGateway::InternalSwap(FromGateway* other) {
  using std::swap;
  gateway_key_.Swap(&other->gateway_key_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  gateway_string_.Swap(&other->gateway_string_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(gateway_time_, other->gateway_time_);
  swap(gateway_double_, other->gateway_double_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata FromGateway::GetMetadata() const {
  protobuf_gateway_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_gateway_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void ToGateway::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ToGateway::kClientTimeFieldNumber;
const int ToGateway::kClientKeyFieldNumber;
const int ToGateway::kClientStringFieldNumber;
const int ToGateway::kClientDoubleFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ToGateway::ToGateway()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_gateway_2eproto::scc_info_ToGateway.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:moos.gateway.ToGateway)
}
ToGateway::ToGateway(const ToGateway& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  client_key_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_client_key()) {
    client_key_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.client_key_);
  }
  client_string_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_client_string()) {
    client_string_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.client_string_);
  }
  ::memcpy(&client_time_, &from.client_time_,
    static_cast<size_t>(reinterpret_cast<char*>(&client_double_) -
    reinterpret_cast<char*>(&client_time_)) + sizeof(client_double_));
  // @@protoc_insertion_point(copy_constructor:moos.gateway.ToGateway)
}

void ToGateway::SharedCtor() {
  client_key_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  client_string_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&client_time_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&client_double_) -
      reinterpret_cast<char*>(&client_time_)) + sizeof(client_double_));
}

ToGateway::~ToGateway() {
  // @@protoc_insertion_point(destructor:moos.gateway.ToGateway)
  SharedDtor();
}

void ToGateway::SharedDtor() {
  client_key_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  client_string_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ToGateway::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ToGateway::descriptor() {
  ::protobuf_gateway_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_gateway_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ToGateway& ToGateway::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_gateway_2eproto::scc_info_ToGateway.base);
  return *internal_default_instance();
}


void ToGateway::Clear() {
// @@protoc_insertion_point(message_clear_start:moos.gateway.ToGateway)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      client_key_.ClearNonDefaultToEmptyNoArena();
    }
    if (cached_has_bits & 0x00000002u) {
      client_string_.ClearNonDefaultToEmptyNoArena();
    }
  }
  if (cached_has_bits & 12u) {
    ::memset(&client_time_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&client_double_) -
        reinterpret_cast<char*>(&client_time_)) + sizeof(client_double_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ToGateway::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:moos.gateway.ToGateway)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double client_time = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {
          set_has_client_time();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &client_time_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string client_key = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_client_key()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->client_key().data(), static_cast<int>(this->client_key().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "moos.gateway.ToGateway.client_key");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string client_string = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_client_string()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->client_string().data(), static_cast<int>(this->client_string().length()),
            ::google::protobuf::internal::WireFormat::PARSE,
            "moos.gateway.ToGateway.client_string");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional double client_double = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(33u /* 33 & 0xFF */)) {
          set_has_client_double();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &client_double_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:moos.gateway.ToGateway)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:moos.gateway.ToGateway)
  return false;
#undef DO_
}

void ToGateway::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:moos.gateway.ToGateway)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional double client_time = 1;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->client_time(), output);
  }

  // optional string client_key = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_key().data(), static_cast<int>(this->client_key().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.ToGateway.client_key");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->client_key(), output);
  }

  // optional string client_string = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_string().data(), static_cast<int>(this->client_string().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.ToGateway.client_string");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->client_string(), output);
  }

  // optional double client_double = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->client_double(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:moos.gateway.ToGateway)
}

::google::protobuf::uint8* ToGateway::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:moos.gateway.ToGateway)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional double client_time = 1;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->client_time(), target);
  }

  // optional string client_key = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_key().data(), static_cast<int>(this->client_key().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.ToGateway.client_key");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->client_key(), target);
  }

  // optional string client_string = 3;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->client_string().data(), static_cast<int>(this->client_string().length()),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "moos.gateway.ToGateway.client_string");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->client_string(), target);
  }

  // optional double client_double = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->client_double(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:moos.gateway.ToGateway)
  return target;
}

size_t ToGateway::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:moos.gateway.ToGateway)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 15u) {
    // optional string client_key = 2;
    if (has_client_key()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->client_key());
    }

    // optional string client_string = 3;
    if (has_client_string()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->client_string());
    }

    // optional double client_time = 1;
    if (has_client_time()) {
      total_size += 1 + 8;
    }

    // optional double client_double = 4;
    if (has_client_double()) {
      total_size += 1 + 8;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ToGateway::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:moos.gateway.ToGateway)
  GOOGLE_DCHECK_NE(&from, this);
  const ToGateway* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ToGateway>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:moos.gateway.ToGateway)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:moos.gateway.ToGateway)
    MergeFrom(*source);
  }
}

void ToGateway::MergeFrom(const ToGateway& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:moos.gateway.ToGateway)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 15u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_client_key();
      client_key_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.client_key_);
    }
    if (cached_has_bits & 0x00000002u) {
      set_has_client_string();
      client_string_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.client_string_);
    }
    if (cached_has_bits & 0x00000004u) {
      client_time_ = from.client_time_;
    }
    if (cached_has_bits & 0x00000008u) {
      client_double_ = from.client_double_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ToGateway::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:moos.gateway.ToGateway)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ToGateway::CopyFrom(const ToGateway& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:moos.gateway.ToGateway)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ToGateway::IsInitialized() const {
  return true;
}

void ToGateway::Swap(ToGateway* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ToGateway::InternalSwap(ToGateway* other) {
  using std::swap;
  client_key_.Swap(&other->client_key_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  client_string_.Swap(&other->client_string_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(client_time_, other->client_time_);
  swap(client_double_, other->client_double_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ToGateway::GetMetadata() const {
  protobuf_gateway_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_gateway_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace gateway
}  // namespace moos
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::moos::gateway::FromGateway* Arena::CreateMaybeMessage< ::moos::gateway::FromGateway >(Arena* arena) {
  return Arena::CreateInternal< ::moos::gateway::FromGateway >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::moos::gateway::ToGateway* Arena::CreateMaybeMessage< ::moos::gateway::ToGateway >(Arena* arena) {
  return Arena::CreateInternal< ::moos::gateway::ToGateway >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
