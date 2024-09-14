// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sun_interfaces:srv/PizzaPose.idl
// generated code does not contain a copyright notice

#ifndef SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__STRUCT_HPP_
#define SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sun_interfaces__srv__PizzaPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__sun_interfaces__srv__PizzaPose_Request __declspec(deprecated)
#endif

namespace sun_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PizzaPose_Request_
{
  using Type = PizzaPose_Request_<ContainerAllocator>;

  explicit PizzaPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->number = 0l;
    }
  }

  explicit PizzaPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->number = 0l;
    }
  }

  // field types and members
  using _x_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _x_type x;
  using _y_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _y_type y;
  using _number_type =
    int32_t;
  _number_type number;

  // setters for named parameter idiom
  Type & set__x(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__number(
    const int32_t & _arg)
  {
    this->number = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sun_interfaces__srv__PizzaPose_Request
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sun_interfaces__srv__PizzaPose_Request
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PizzaPose_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->number != other.number) {
      return false;
    }
    return true;
  }
  bool operator!=(const PizzaPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PizzaPose_Request_

// alias to use template instance with default allocator
using PizzaPose_Request =
  sun_interfaces::srv::PizzaPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sun_interfaces


#ifndef _WIN32
# define DEPRECATED__sun_interfaces__srv__PizzaPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__sun_interfaces__srv__PizzaPose_Response __declspec(deprecated)
#endif

namespace sun_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PizzaPose_Response_
{
  using Type = PizzaPose_Response_<ContainerAllocator>;

  explicit PizzaPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit PizzaPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sun_interfaces__srv__PizzaPose_Response
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sun_interfaces__srv__PizzaPose_Response
    std::shared_ptr<sun_interfaces::srv::PizzaPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PizzaPose_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const PizzaPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PizzaPose_Response_

// alias to use template instance with default allocator
using PizzaPose_Response =
  sun_interfaces::srv::PizzaPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace sun_interfaces

namespace sun_interfaces
{

namespace srv
{

struct PizzaPose
{
  using Request = sun_interfaces::srv::PizzaPose_Request;
  using Response = sun_interfaces::srv::PizzaPose_Response;
};

}  // namespace srv

}  // namespace sun_interfaces

#endif  // SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__STRUCT_HPP_
