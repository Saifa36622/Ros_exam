// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sun_interfaces:srv/PizzaPose.idl
// generated code does not contain a copyright notice
#include "sun_interfaces/srv/detail/pizza_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `x`
// Member `y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
sun_interfaces__srv__PizzaPose_Request__init(sun_interfaces__srv__PizzaPose_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__float__Sequence__init(&msg->x, 0)) {
    sun_interfaces__srv__PizzaPose_Request__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__float__Sequence__init(&msg->y, 0)) {
    sun_interfaces__srv__PizzaPose_Request__fini(msg);
    return false;
  }
  // number
  return true;
}

void
sun_interfaces__srv__PizzaPose_Request__fini(sun_interfaces__srv__PizzaPose_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  rosidl_runtime_c__float__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__float__Sequence__fini(&msg->y);
  // number
}

bool
sun_interfaces__srv__PizzaPose_Request__are_equal(const sun_interfaces__srv__PizzaPose_Request * lhs, const sun_interfaces__srv__PizzaPose_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // number
  if (lhs->number != rhs->number) {
    return false;
  }
  return true;
}

bool
sun_interfaces__srv__PizzaPose_Request__copy(
  const sun_interfaces__srv__PizzaPose_Request * input,
  sun_interfaces__srv__PizzaPose_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // number
  output->number = input->number;
  return true;
}

sun_interfaces__srv__PizzaPose_Request *
sun_interfaces__srv__PizzaPose_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sun_interfaces__srv__PizzaPose_Request * msg = (sun_interfaces__srv__PizzaPose_Request *)allocator.allocate(sizeof(sun_interfaces__srv__PizzaPose_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sun_interfaces__srv__PizzaPose_Request));
  bool success = sun_interfaces__srv__PizzaPose_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sun_interfaces__srv__PizzaPose_Request__destroy(sun_interfaces__srv__PizzaPose_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sun_interfaces__srv__PizzaPose_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sun_interfaces__srv__PizzaPose_Request__Sequence__init(sun_interfaces__srv__PizzaPose_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sun_interfaces__srv__PizzaPose_Request * data = NULL;

  if (size) {
    data = (sun_interfaces__srv__PizzaPose_Request *)allocator.zero_allocate(size, sizeof(sun_interfaces__srv__PizzaPose_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sun_interfaces__srv__PizzaPose_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sun_interfaces__srv__PizzaPose_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sun_interfaces__srv__PizzaPose_Request__Sequence__fini(sun_interfaces__srv__PizzaPose_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sun_interfaces__srv__PizzaPose_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sun_interfaces__srv__PizzaPose_Request__Sequence *
sun_interfaces__srv__PizzaPose_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sun_interfaces__srv__PizzaPose_Request__Sequence * array = (sun_interfaces__srv__PizzaPose_Request__Sequence *)allocator.allocate(sizeof(sun_interfaces__srv__PizzaPose_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sun_interfaces__srv__PizzaPose_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sun_interfaces__srv__PizzaPose_Request__Sequence__destroy(sun_interfaces__srv__PizzaPose_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sun_interfaces__srv__PizzaPose_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sun_interfaces__srv__PizzaPose_Request__Sequence__are_equal(const sun_interfaces__srv__PizzaPose_Request__Sequence * lhs, const sun_interfaces__srv__PizzaPose_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sun_interfaces__srv__PizzaPose_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sun_interfaces__srv__PizzaPose_Request__Sequence__copy(
  const sun_interfaces__srv__PizzaPose_Request__Sequence * input,
  sun_interfaces__srv__PizzaPose_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sun_interfaces__srv__PizzaPose_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sun_interfaces__srv__PizzaPose_Request * data =
      (sun_interfaces__srv__PizzaPose_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sun_interfaces__srv__PizzaPose_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sun_interfaces__srv__PizzaPose_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sun_interfaces__srv__PizzaPose_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
sun_interfaces__srv__PizzaPose_Response__init(sun_interfaces__srv__PizzaPose_Response * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
sun_interfaces__srv__PizzaPose_Response__fini(sun_interfaces__srv__PizzaPose_Response * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
sun_interfaces__srv__PizzaPose_Response__are_equal(const sun_interfaces__srv__PizzaPose_Response * lhs, const sun_interfaces__srv__PizzaPose_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
sun_interfaces__srv__PizzaPose_Response__copy(
  const sun_interfaces__srv__PizzaPose_Response * input,
  sun_interfaces__srv__PizzaPose_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

sun_interfaces__srv__PizzaPose_Response *
sun_interfaces__srv__PizzaPose_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sun_interfaces__srv__PizzaPose_Response * msg = (sun_interfaces__srv__PizzaPose_Response *)allocator.allocate(sizeof(sun_interfaces__srv__PizzaPose_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sun_interfaces__srv__PizzaPose_Response));
  bool success = sun_interfaces__srv__PizzaPose_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sun_interfaces__srv__PizzaPose_Response__destroy(sun_interfaces__srv__PizzaPose_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sun_interfaces__srv__PizzaPose_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sun_interfaces__srv__PizzaPose_Response__Sequence__init(sun_interfaces__srv__PizzaPose_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sun_interfaces__srv__PizzaPose_Response * data = NULL;

  if (size) {
    data = (sun_interfaces__srv__PizzaPose_Response *)allocator.zero_allocate(size, sizeof(sun_interfaces__srv__PizzaPose_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sun_interfaces__srv__PizzaPose_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sun_interfaces__srv__PizzaPose_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
sun_interfaces__srv__PizzaPose_Response__Sequence__fini(sun_interfaces__srv__PizzaPose_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      sun_interfaces__srv__PizzaPose_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

sun_interfaces__srv__PizzaPose_Response__Sequence *
sun_interfaces__srv__PizzaPose_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sun_interfaces__srv__PizzaPose_Response__Sequence * array = (sun_interfaces__srv__PizzaPose_Response__Sequence *)allocator.allocate(sizeof(sun_interfaces__srv__PizzaPose_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sun_interfaces__srv__PizzaPose_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sun_interfaces__srv__PizzaPose_Response__Sequence__destroy(sun_interfaces__srv__PizzaPose_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sun_interfaces__srv__PizzaPose_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sun_interfaces__srv__PizzaPose_Response__Sequence__are_equal(const sun_interfaces__srv__PizzaPose_Response__Sequence * lhs, const sun_interfaces__srv__PizzaPose_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sun_interfaces__srv__PizzaPose_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sun_interfaces__srv__PizzaPose_Response__Sequence__copy(
  const sun_interfaces__srv__PizzaPose_Response__Sequence * input,
  sun_interfaces__srv__PizzaPose_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sun_interfaces__srv__PizzaPose_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sun_interfaces__srv__PizzaPose_Response * data =
      (sun_interfaces__srv__PizzaPose_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sun_interfaces__srv__PizzaPose_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sun_interfaces__srv__PizzaPose_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sun_interfaces__srv__PizzaPose_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
