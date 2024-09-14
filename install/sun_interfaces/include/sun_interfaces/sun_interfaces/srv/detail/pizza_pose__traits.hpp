// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sun_interfaces:srv/PizzaPose.idl
// generated code does not contain a copyright notice

#ifndef SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__TRAITS_HPP_
#define SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sun_interfaces/srv/detail/pizza_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sun_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PizzaPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    if (msg.x.size() == 0) {
      out << "x: []";
    } else {
      out << "x: [";
      size_t pending_items = msg.x.size();
      for (auto item : msg.x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y
  {
    if (msg.y.size() == 0) {
      out << "y: []";
    } else {
      out << "y: [";
      size_t pending_items = msg.y.size();
      for (auto item : msg.y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: number
  {
    out << "number: ";
    rosidl_generator_traits::value_to_yaml(msg.number, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PizzaPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x.size() == 0) {
      out << "x: []\n";
    } else {
      out << "x:\n";
      for (auto item : msg.x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y.size() == 0) {
      out << "y: []\n";
    } else {
      out << "y:\n";
      for (auto item : msg.y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "number: ";
    rosidl_generator_traits::value_to_yaml(msg.number, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PizzaPose_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sun_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sun_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sun_interfaces::srv::PizzaPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  sun_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sun_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const sun_interfaces::srv::PizzaPose_Request & msg)
{
  return sun_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sun_interfaces::srv::PizzaPose_Request>()
{
  return "sun_interfaces::srv::PizzaPose_Request";
}

template<>
inline const char * name<sun_interfaces::srv::PizzaPose_Request>()
{
  return "sun_interfaces/srv/PizzaPose_Request";
}

template<>
struct has_fixed_size<sun_interfaces::srv::PizzaPose_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<sun_interfaces::srv::PizzaPose_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<sun_interfaces::srv::PizzaPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace sun_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PizzaPose_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: isfinish
  {
    out << "isfinish: ";
    rosidl_generator_traits::value_to_yaml(msg.isfinish, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PizzaPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: isfinish
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "isfinish: ";
    rosidl_generator_traits::value_to_yaml(msg.isfinish, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PizzaPose_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace sun_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use sun_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sun_interfaces::srv::PizzaPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  sun_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sun_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const sun_interfaces::srv::PizzaPose_Response & msg)
{
  return sun_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<sun_interfaces::srv::PizzaPose_Response>()
{
  return "sun_interfaces::srv::PizzaPose_Response";
}

template<>
inline const char * name<sun_interfaces::srv::PizzaPose_Response>()
{
  return "sun_interfaces/srv/PizzaPose_Response";
}

template<>
struct has_fixed_size<sun_interfaces::srv::PizzaPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sun_interfaces::srv::PizzaPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sun_interfaces::srv::PizzaPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<sun_interfaces::srv::PizzaPose>()
{
  return "sun_interfaces::srv::PizzaPose";
}

template<>
inline const char * name<sun_interfaces::srv::PizzaPose>()
{
  return "sun_interfaces/srv/PizzaPose";
}

template<>
struct has_fixed_size<sun_interfaces::srv::PizzaPose>
  : std::integral_constant<
    bool,
    has_fixed_size<sun_interfaces::srv::PizzaPose_Request>::value &&
    has_fixed_size<sun_interfaces::srv::PizzaPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<sun_interfaces::srv::PizzaPose>
  : std::integral_constant<
    bool,
    has_bounded_size<sun_interfaces::srv::PizzaPose_Request>::value &&
    has_bounded_size<sun_interfaces::srv::PizzaPose_Response>::value
  >
{
};

template<>
struct is_service<sun_interfaces::srv::PizzaPose>
  : std::true_type
{
};

template<>
struct is_service_request<sun_interfaces::srv::PizzaPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<sun_interfaces::srv::PizzaPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SUN_INTERFACES__SRV__DETAIL__PIZZA_POSE__TRAITS_HPP_
