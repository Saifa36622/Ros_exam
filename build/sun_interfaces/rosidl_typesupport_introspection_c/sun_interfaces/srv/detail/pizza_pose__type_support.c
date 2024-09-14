// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from sun_interfaces:srv/PizzaPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "sun_interfaces/srv/detail/pizza_pose__rosidl_typesupport_introspection_c.h"
#include "sun_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "sun_interfaces/srv/detail/pizza_pose__functions.h"
#include "sun_interfaces/srv/detail/pizza_pose__struct.h"


// Include directives for member types
// Member `x`
// Member `y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sun_interfaces__srv__PizzaPose_Request__init(message_memory);
}

void sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_fini_function(void * message_memory)
{
  sun_interfaces__srv__PizzaPose_Request__fini(message_memory);
}

size_t sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__size_function__PizzaPose_Request__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_const_function__PizzaPose_Request__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_function__PizzaPose_Request__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__fetch_function__PizzaPose_Request__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_const_function__PizzaPose_Request__x(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__assign_function__PizzaPose_Request__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_function__PizzaPose_Request__x(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__resize_function__PizzaPose_Request__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__size_function__PizzaPose_Request__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_const_function__PizzaPose_Request__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_function__PizzaPose_Request__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__fetch_function__PizzaPose_Request__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_const_function__PizzaPose_Request__y(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__assign_function__PizzaPose_Request__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_function__PizzaPose_Request__y(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__resize_function__PizzaPose_Request__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sun_interfaces__srv__PizzaPose_Request, x),  // bytes offset in struct
    NULL,  // default value
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__size_function__PizzaPose_Request__x,  // size() function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_const_function__PizzaPose_Request__x,  // get_const(index) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_function__PizzaPose_Request__x,  // get(index) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__fetch_function__PizzaPose_Request__x,  // fetch(index, &value) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__assign_function__PizzaPose_Request__x,  // assign(index, value) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__resize_function__PizzaPose_Request__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sun_interfaces__srv__PizzaPose_Request, y),  // bytes offset in struct
    NULL,  // default value
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__size_function__PizzaPose_Request__y,  // size() function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_const_function__PizzaPose_Request__y,  // get_const(index) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__get_function__PizzaPose_Request__y,  // get(index) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__fetch_function__PizzaPose_Request__y,  // fetch(index, &value) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__assign_function__PizzaPose_Request__y,  // assign(index, value) function pointer
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__resize_function__PizzaPose_Request__y  // resize(index) function pointer
  },
  {
    "number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sun_interfaces__srv__PizzaPose_Request, number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_members = {
  "sun_interfaces__srv",  // message namespace
  "PizzaPose_Request",  // message name
  3,  // number of fields
  sizeof(sun_interfaces__srv__PizzaPose_Request),
  sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_member_array,  // message members
  sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_type_support_handle = {
  0,
  &sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sun_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sun_interfaces, srv, PizzaPose_Request)() {
  if (!sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_type_support_handle.typesupport_identifier) {
    sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sun_interfaces__srv__PizzaPose_Request__rosidl_typesupport_introspection_c__PizzaPose_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "sun_interfaces/srv/detail/pizza_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "sun_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "sun_interfaces/srv/detail/pizza_pose__functions.h"
// already included above
// #include "sun_interfaces/srv/detail/pizza_pose__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  sun_interfaces__srv__PizzaPose_Response__init(message_memory);
}

void sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_fini_function(void * message_memory)
{
  sun_interfaces__srv__PizzaPose_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(sun_interfaces__srv__PizzaPose_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_members = {
  "sun_interfaces__srv",  // message namespace
  "PizzaPose_Response",  // message name
  1,  // number of fields
  sizeof(sun_interfaces__srv__PizzaPose_Response),
  sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_member_array,  // message members
  sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_type_support_handle = {
  0,
  &sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sun_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sun_interfaces, srv, PizzaPose_Response)() {
  if (!sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_type_support_handle.typesupport_identifier) {
    sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &sun_interfaces__srv__PizzaPose_Response__rosidl_typesupport_introspection_c__PizzaPose_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "sun_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "sun_interfaces/srv/detail/pizza_pose__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_service_members = {
  "sun_interfaces__srv",  // service namespace
  "PizzaPose",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_Request_message_type_support_handle,
  NULL  // response message
  // sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_Response_message_type_support_handle
};

static rosidl_service_type_support_t sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_service_type_support_handle = {
  0,
  &sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sun_interfaces, srv, PizzaPose_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sun_interfaces, srv, PizzaPose_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_sun_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sun_interfaces, srv, PizzaPose)() {
  if (!sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_service_type_support_handle.typesupport_identifier) {
    sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sun_interfaces, srv, PizzaPose_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sun_interfaces, srv, PizzaPose_Response)()->data;
  }

  return &sun_interfaces__srv__detail__pizza_pose__rosidl_typesupport_introspection_c__PizzaPose_service_type_support_handle;
}
