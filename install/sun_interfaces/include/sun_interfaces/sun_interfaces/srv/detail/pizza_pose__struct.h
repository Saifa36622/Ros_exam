// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sun_interfaces:srv/PizzaPose.idl
// generated code does not contain a copyright notice

#ifndef SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__STRUCT_H_
#define SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'x'
// Member 'y'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/PizzaPose in the package sun_interfaces.
typedef struct sun_interfaces__srv__PizzaPose_Request
{
  rosidl_runtime_c__float__Sequence x;
  rosidl_runtime_c__float__Sequence y;
  /// The number of times this data has been sent
  int32_t number;
} sun_interfaces__srv__PizzaPose_Request;

// Struct for a sequence of sun_interfaces__srv__PizzaPose_Request.
typedef struct sun_interfaces__srv__PizzaPose_Request__Sequence
{
  sun_interfaces__srv__PizzaPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sun_interfaces__srv__PizzaPose_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PizzaPose in the package sun_interfaces.
typedef struct sun_interfaces__srv__PizzaPose_Response
{
  uint8_t structure_needs_at_least_one_member;
} sun_interfaces__srv__PizzaPose_Response;

// Struct for a sequence of sun_interfaces__srv__PizzaPose_Response.
typedef struct sun_interfaces__srv__PizzaPose_Response__Sequence
{
  sun_interfaces__srv__PizzaPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sun_interfaces__srv__PizzaPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__STRUCT_H_
