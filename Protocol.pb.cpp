// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Protocol.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* ArrayInt_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArrayInt_reflection_ = NULL;
const ::google::protobuf::Descriptor* HeadProtocol_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HeadProtocol_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Protocol_2eproto() {
  protobuf_AddDesc_Protocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Protocol.proto");
  GOOGLE_CHECK(file != NULL);
  ArrayInt_descriptor_ = file->message_type(0);
  static const int ArrayInt_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArrayInt, arrayint_),
  };
  ArrayInt_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ArrayInt_descriptor_,
      ArrayInt::default_instance_,
      ArrayInt_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArrayInt, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArrayInt, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ArrayInt));
  HeadProtocol_descriptor_ = file->message_type(1);
  static const int HeadProtocol_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, access_point_fd_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, source_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, pass_by_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, proto_body_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, proto_body_status_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, proto_body_name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, proto_body_buffer_),
  };
  HeadProtocol_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HeadProtocol_descriptor_,
      HeadProtocol::default_instance_,
      HeadProtocol_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HeadProtocol, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HeadProtocol));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Protocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ArrayInt_descriptor_, &ArrayInt::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HeadProtocol_descriptor_, &HeadProtocol::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Protocol_2eproto() {
  delete ArrayInt::default_instance_;
  delete ArrayInt_reflection_;
  delete HeadProtocol::default_instance_;
  delete HeadProtocol_reflection_;
}

void protobuf_AddDesc_Protocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016Protocol.proto\"\034\n\010ArrayInt\022\020\n\010arrayInt"
    "\030\001 \003(\005\"\301\001\n\014HeadProtocol\022\027\n\017access_point_"
    "fd\030\001 \001(\005\022\021\n\tsource_id\030\002 \001(\005\022\035\n\npass_by_i"
    "d\030\003 \001(\0132\t.ArrayInt\022\027\n\017proto_body_size\030\004 "
    "\001(\005\022\031\n\021proto_body_status\030\005 \001(\005\022\027\n\017proto_"
    "body_name\030\006 \001(\t\022\031\n\021proto_body_buffer\030\007 \001"
    "(\t", 242);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Protocol.proto", &protobuf_RegisterTypes);
  ArrayInt::default_instance_ = new ArrayInt();
  HeadProtocol::default_instance_ = new HeadProtocol();
  ArrayInt::default_instance_->InitAsDefaultInstance();
  HeadProtocol::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Protocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Protocol_2eproto {
  StaticDescriptorInitializer_Protocol_2eproto() {
    protobuf_AddDesc_Protocol_2eproto();
  }
} static_descriptor_initializer_Protocol_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ArrayInt::kArrayIntFieldNumber;
#endif  // !_MSC_VER

ArrayInt::ArrayInt()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ArrayInt)
}

void ArrayInt::InitAsDefaultInstance() {
}

ArrayInt::ArrayInt(const ArrayInt& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ArrayInt)
}

void ArrayInt::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArrayInt::~ArrayInt() {
  // @@protoc_insertion_point(destructor:ArrayInt)
  SharedDtor();
}

void ArrayInt::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ArrayInt::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArrayInt::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArrayInt_descriptor_;
}

const ArrayInt& ArrayInt::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_2eproto();
  return *default_instance_;
}

ArrayInt* ArrayInt::default_instance_ = NULL;

ArrayInt* ArrayInt::New() const {
  return new ArrayInt;
}

void ArrayInt::Clear() {
  arrayint_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ArrayInt::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ArrayInt)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated int32 arrayInt = 1;
      case 1: {
        if (tag == 8) {
         parse_arrayInt:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 8, input, this->mutable_arrayint())));
        } else if (tag == 10) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_arrayint())));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(8)) goto parse_arrayInt;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ArrayInt)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ArrayInt)
  return false;
#undef DO_
}

void ArrayInt::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ArrayInt)
  // repeated int32 arrayInt = 1;
  for (int i = 0; i < this->arrayint_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      1, this->arrayint(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ArrayInt)
}

::google::protobuf::uint8* ArrayInt::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ArrayInt)
  // repeated int32 arrayInt = 1;
  for (int i = 0; i < this->arrayint_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(1, this->arrayint(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ArrayInt)
  return target;
}

int ArrayInt::ByteSize() const {
  int total_size = 0;

  // repeated int32 arrayInt = 1;
  {
    int data_size = 0;
    for (int i = 0; i < this->arrayint_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->arrayint(i));
    }
    total_size += 1 * this->arrayint_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArrayInt::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ArrayInt* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ArrayInt*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArrayInt::MergeFrom(const ArrayInt& from) {
  GOOGLE_CHECK_NE(&from, this);
  arrayint_.MergeFrom(from.arrayint_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ArrayInt::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArrayInt::CopyFrom(const ArrayInt& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArrayInt::IsInitialized() const {

  return true;
}

void ArrayInt::Swap(ArrayInt* other) {
  if (other != this) {
    arrayint_.Swap(&other->arrayint_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ArrayInt::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArrayInt_descriptor_;
  metadata.reflection = ArrayInt_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int HeadProtocol::kAccessPointFdFieldNumber;
const int HeadProtocol::kSourceIdFieldNumber;
const int HeadProtocol::kPassByIdFieldNumber;
const int HeadProtocol::kProtoBodySizeFieldNumber;
const int HeadProtocol::kProtoBodyStatusFieldNumber;
const int HeadProtocol::kProtoBodyNameFieldNumber;
const int HeadProtocol::kProtoBodyBufferFieldNumber;
#endif  // !_MSC_VER

HeadProtocol::HeadProtocol()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:HeadProtocol)
}

void HeadProtocol::InitAsDefaultInstance() {
  pass_by_id_ = const_cast< ::ArrayInt*>(&::ArrayInt::default_instance());
}

HeadProtocol::HeadProtocol(const HeadProtocol& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:HeadProtocol)
}

void HeadProtocol::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  access_point_fd_ = 0;
  source_id_ = 0;
  pass_by_id_ = NULL;
  proto_body_size_ = 0;
  proto_body_status_ = 0;
  proto_body_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  proto_body_buffer_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HeadProtocol::~HeadProtocol() {
  // @@protoc_insertion_point(destructor:HeadProtocol)
  SharedDtor();
}

void HeadProtocol::SharedDtor() {
  if (proto_body_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete proto_body_name_;
  }
  if (proto_body_buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete proto_body_buffer_;
  }
  if (this != default_instance_) {
    delete pass_by_id_;
  }
}

void HeadProtocol::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HeadProtocol::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HeadProtocol_descriptor_;
}

const HeadProtocol& HeadProtocol::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_2eproto();
  return *default_instance_;
}

HeadProtocol* HeadProtocol::default_instance_ = NULL;

HeadProtocol* HeadProtocol::New() const {
  return new HeadProtocol;
}

void HeadProtocol::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<HeadProtocol*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 127) {
    ZR_(access_point_fd_, source_id_);
    ZR_(proto_body_size_, proto_body_status_);
    if (has_pass_by_id()) {
      if (pass_by_id_ != NULL) pass_by_id_->::ArrayInt::Clear();
    }
    if (has_proto_body_name()) {
      if (proto_body_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        proto_body_name_->clear();
      }
    }
    if (has_proto_body_buffer()) {
      if (proto_body_buffer_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        proto_body_buffer_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HeadProtocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:HeadProtocol)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 access_point_fd = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &access_point_fd_)));
          set_has_access_point_fd();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_source_id;
        break;
      }

      // optional int32 source_id = 2;
      case 2: {
        if (tag == 16) {
         parse_source_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &source_id_)));
          set_has_source_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_pass_by_id;
        break;
      }

      // optional .ArrayInt pass_by_id = 3;
      case 3: {
        if (tag == 26) {
         parse_pass_by_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_pass_by_id()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_proto_body_size;
        break;
      }

      // optional int32 proto_body_size = 4;
      case 4: {
        if (tag == 32) {
         parse_proto_body_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &proto_body_size_)));
          set_has_proto_body_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_proto_body_status;
        break;
      }

      // optional int32 proto_body_status = 5;
      case 5: {
        if (tag == 40) {
         parse_proto_body_status:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &proto_body_status_)));
          set_has_proto_body_status();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_proto_body_name;
        break;
      }

      // optional string proto_body_name = 6;
      case 6: {
        if (tag == 50) {
         parse_proto_body_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_proto_body_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->proto_body_name().data(), this->proto_body_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "proto_body_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(58)) goto parse_proto_body_buffer;
        break;
      }

      // optional string proto_body_buffer = 7;
      case 7: {
        if (tag == 58) {
         parse_proto_body_buffer:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_proto_body_buffer()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->proto_body_buffer().data(), this->proto_body_buffer().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "proto_body_buffer");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:HeadProtocol)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:HeadProtocol)
  return false;
#undef DO_
}

void HeadProtocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:HeadProtocol)
  // optional int32 access_point_fd = 1;
  if (has_access_point_fd()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->access_point_fd(), output);
  }

  // optional int32 source_id = 2;
  if (has_source_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->source_id(), output);
  }

  // optional .ArrayInt pass_by_id = 3;
  if (has_pass_by_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->pass_by_id(), output);
  }

  // optional int32 proto_body_size = 4;
  if (has_proto_body_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->proto_body_size(), output);
  }

  // optional int32 proto_body_status = 5;
  if (has_proto_body_status()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->proto_body_status(), output);
  }

  // optional string proto_body_name = 6;
  if (has_proto_body_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->proto_body_name().data(), this->proto_body_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "proto_body_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->proto_body_name(), output);
  }

  // optional string proto_body_buffer = 7;
  if (has_proto_body_buffer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->proto_body_buffer().data(), this->proto_body_buffer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "proto_body_buffer");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      7, this->proto_body_buffer(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:HeadProtocol)
}

::google::protobuf::uint8* HeadProtocol::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:HeadProtocol)
  // optional int32 access_point_fd = 1;
  if (has_access_point_fd()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->access_point_fd(), target);
  }

  // optional int32 source_id = 2;
  if (has_source_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->source_id(), target);
  }

  // optional .ArrayInt pass_by_id = 3;
  if (has_pass_by_id()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->pass_by_id(), target);
  }

  // optional int32 proto_body_size = 4;
  if (has_proto_body_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->proto_body_size(), target);
  }

  // optional int32 proto_body_status = 5;
  if (has_proto_body_status()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->proto_body_status(), target);
  }

  // optional string proto_body_name = 6;
  if (has_proto_body_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->proto_body_name().data(), this->proto_body_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "proto_body_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->proto_body_name(), target);
  }

  // optional string proto_body_buffer = 7;
  if (has_proto_body_buffer()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->proto_body_buffer().data(), this->proto_body_buffer().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "proto_body_buffer");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        7, this->proto_body_buffer(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:HeadProtocol)
  return target;
}

int HeadProtocol::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 access_point_fd = 1;
    if (has_access_point_fd()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->access_point_fd());
    }

    // optional int32 source_id = 2;
    if (has_source_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->source_id());
    }

    // optional .ArrayInt pass_by_id = 3;
    if (has_pass_by_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->pass_by_id());
    }

    // optional int32 proto_body_size = 4;
    if (has_proto_body_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->proto_body_size());
    }

    // optional int32 proto_body_status = 5;
    if (has_proto_body_status()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->proto_body_status());
    }

    // optional string proto_body_name = 6;
    if (has_proto_body_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->proto_body_name());
    }

    // optional string proto_body_buffer = 7;
    if (has_proto_body_buffer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->proto_body_buffer());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HeadProtocol::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HeadProtocol* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HeadProtocol*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HeadProtocol::MergeFrom(const HeadProtocol& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_access_point_fd()) {
      set_access_point_fd(from.access_point_fd());
    }
    if (from.has_source_id()) {
      set_source_id(from.source_id());
    }
    if (from.has_pass_by_id()) {
      mutable_pass_by_id()->::ArrayInt::MergeFrom(from.pass_by_id());
    }
    if (from.has_proto_body_size()) {
      set_proto_body_size(from.proto_body_size());
    }
    if (from.has_proto_body_status()) {
      set_proto_body_status(from.proto_body_status());
    }
    if (from.has_proto_body_name()) {
      set_proto_body_name(from.proto_body_name());
    }
    if (from.has_proto_body_buffer()) {
      set_proto_body_buffer(from.proto_body_buffer());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HeadProtocol::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HeadProtocol::CopyFrom(const HeadProtocol& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeadProtocol::IsInitialized() const {

  return true;
}

void HeadProtocol::Swap(HeadProtocol* other) {
  if (other != this) {
    std::swap(access_point_fd_, other->access_point_fd_);
    std::swap(source_id_, other->source_id_);
    std::swap(pass_by_id_, other->pass_by_id_);
    std::swap(proto_body_size_, other->proto_body_size_);
    std::swap(proto_body_status_, other->proto_body_status_);
    std::swap(proto_body_name_, other->proto_body_name_);
    std::swap(proto_body_buffer_, other->proto_body_buffer_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HeadProtocol::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HeadProtocol_descriptor_;
  metadata.reflection = HeadProtocol_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
