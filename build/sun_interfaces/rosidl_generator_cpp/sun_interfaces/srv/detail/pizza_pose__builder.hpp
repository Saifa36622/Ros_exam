// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sun_interfaces:srv/PizzaPose.idl
// generated code does not contain a copyright notice

#ifndef SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__BUILDER_HPP_
#define SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sun_interfaces/srv/detail/pizza_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sun_interfaces
{

namespace srv
{

namespace builder
{

class Init_PizzaPose_Request_number
{
public:
  explicit Init_PizzaPose_Request_number(::sun_interfaces::srv::PizzaPose_Request & msg)
  : msg_(msg)
  {}
  ::sun_interfaces::srv::PizzaPose_Request number(::sun_interfaces::srv::PizzaPose_Request::_number_type arg)
  {
    msg_.number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sun_interfaces::srv::PizzaPose_Request msg_;
};

class Init_PizzaPose_Request_y
{
public:
  explicit Init_PizzaPose_Request_y(::sun_interfaces::srv::PizzaPose_Request & msg)
  : msg_(msg)
  {}
  Init_PizzaPose_Request_number y(::sun_interfaces::srv::PizzaPose_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PizzaPose_Request_number(msg_);
  }

private:
  ::sun_interfaces::srv::PizzaPose_Request msg_;
};

class Init_PizzaPose_Request_x
{
public:
  Init_PizzaPose_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PizzaPose_Request_y x(::sun_interfaces::srv::PizzaPose_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PizzaPose_Request_y(msg_);
  }

private:
  ::sun_interfaces::srv::PizzaPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sun_interfaces::srv::PizzaPose_Request>()
{
  return sun_interfaces::srv::builder::Init_PizzaPose_Request_x();
}

}  // namespace sun_interfaces


namespace sun_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::sun_interfaces::srv::PizzaPose_Response>()
{
  return ::sun_interfaces::srv::PizzaPose_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace sun_interfaces

#endif  // SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__BUILDER_HPP_
