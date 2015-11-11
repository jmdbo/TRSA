// Generated by gencpp from file t2_package/Activate.msg
// DO NOT EDIT!


#ifndef T2_PACKAGE_MESSAGE_ACTIVATE_H
#define T2_PACKAGE_MESSAGE_ACTIVATE_H

#include <ros/service_traits.h>


#include <t2_package/ActivateRequest.h>
#include <t2_package/ActivateResponse.h>


namespace t2_package
{

struct Activate
{

typedef ActivateRequest Request;
typedef ActivateResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Activate
} // namespace t2_package


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::t2_package::Activate > {
  static const char* value()
  {
    return "d10b09b6bc031ed40715d35551db280c";
  }

  static const char* value(const ::t2_package::Activate&) { return value(); }
};

template<>
struct DataType< ::t2_package::Activate > {
  static const char* value()
  {
    return "t2_package/Activate";
  }

  static const char* value(const ::t2_package::Activate&) { return value(); }
};


// service_traits::MD5Sum< ::t2_package::ActivateRequest> should match 
// service_traits::MD5Sum< ::t2_package::Activate > 
template<>
struct MD5Sum< ::t2_package::ActivateRequest>
{
  static const char* value()
  {
    return MD5Sum< ::t2_package::Activate >::value();
  }
  static const char* value(const ::t2_package::ActivateRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::t2_package::ActivateRequest> should match 
// service_traits::DataType< ::t2_package::Activate > 
template<>
struct DataType< ::t2_package::ActivateRequest>
{
  static const char* value()
  {
    return DataType< ::t2_package::Activate >::value();
  }
  static const char* value(const ::t2_package::ActivateRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::t2_package::ActivateResponse> should match 
// service_traits::MD5Sum< ::t2_package::Activate > 
template<>
struct MD5Sum< ::t2_package::ActivateResponse>
{
  static const char* value()
  {
    return MD5Sum< ::t2_package::Activate >::value();
  }
  static const char* value(const ::t2_package::ActivateResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::t2_package::ActivateResponse> should match 
// service_traits::DataType< ::t2_package::Activate > 
template<>
struct DataType< ::t2_package::ActivateResponse>
{
  static const char* value()
  {
    return DataType< ::t2_package::Activate >::value();
  }
  static const char* value(const ::t2_package::ActivateResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // T2_PACKAGE_MESSAGE_ACTIVATE_H