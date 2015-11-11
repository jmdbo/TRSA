; Auto-generated. Do not edit!


(cl:in-package t4_package-srv)


;//! \htmlinclude SetTemperature-request.msg.html

(cl:defclass <SetTemperature-request> (roslisp-msg-protocol:ros-message)
  ((temperature
    :reader temperature
    :initarg :temperature
    :type cl:float
    :initform 0.0))
)

(cl:defclass SetTemperature-request (<SetTemperature-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetTemperature-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetTemperature-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t4_package-srv:<SetTemperature-request> is deprecated: use t4_package-srv:SetTemperature-request instead.")))

(cl:ensure-generic-function 'temperature-val :lambda-list '(m))
(cl:defmethod temperature-val ((m <SetTemperature-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t4_package-srv:temperature-val is deprecated.  Use t4_package-srv:temperature instead.")
  (temperature m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetTemperature-request>) ostream)
  "Serializes a message object of type '<SetTemperature-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'temperature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetTemperature-request>) istream)
  "Deserializes a message object of type '<SetTemperature-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'temperature) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetTemperature-request>)))
  "Returns string type for a service object of type '<SetTemperature-request>"
  "t4_package/SetTemperatureRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetTemperature-request)))
  "Returns string type for a service object of type 'SetTemperature-request"
  "t4_package/SetTemperatureRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetTemperature-request>)))
  "Returns md5sum for a message object of type '<SetTemperature-request>"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetTemperature-request)))
  "Returns md5sum for a message object of type 'SetTemperature-request"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetTemperature-request>)))
  "Returns full string definition for message of type '<SetTemperature-request>"
  (cl:format cl:nil "float32 temperature~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetTemperature-request)))
  "Returns full string definition for message of type 'SetTemperature-request"
  (cl:format cl:nil "float32 temperature~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetTemperature-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetTemperature-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetTemperature-request
    (cl:cons ':temperature (temperature msg))
))
;//! \htmlinclude SetTemperature-response.msg.html

(cl:defclass <SetTemperature-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SetTemperature-response (<SetTemperature-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetTemperature-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetTemperature-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t4_package-srv:<SetTemperature-response> is deprecated: use t4_package-srv:SetTemperature-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <SetTemperature-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t4_package-srv:result-val is deprecated.  Use t4_package-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetTemperature-response>) ostream)
  "Serializes a message object of type '<SetTemperature-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetTemperature-response>) istream)
  "Deserializes a message object of type '<SetTemperature-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetTemperature-response>)))
  "Returns string type for a service object of type '<SetTemperature-response>"
  "t4_package/SetTemperatureResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetTemperature-response)))
  "Returns string type for a service object of type 'SetTemperature-response"
  "t4_package/SetTemperatureResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetTemperature-response>)))
  "Returns md5sum for a message object of type '<SetTemperature-response>"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetTemperature-response)))
  "Returns md5sum for a message object of type 'SetTemperature-response"
  "739e57d5bb0983212540786c5e3bf89e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetTemperature-response>)))
  "Returns full string definition for message of type '<SetTemperature-response>"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetTemperature-response)))
  "Returns full string definition for message of type 'SetTemperature-response"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetTemperature-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetTemperature-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetTemperature-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetTemperature)))
  'SetTemperature-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetTemperature)))
  'SetTemperature-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetTemperature)))
  "Returns string type for a service object of type '<SetTemperature>"
  "t4_package/SetTemperature")