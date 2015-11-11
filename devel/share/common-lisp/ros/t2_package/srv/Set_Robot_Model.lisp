; Auto-generated. Do not edit!


(cl:in-package t2_package-srv)


;//! \htmlinclude Set_Robot_Model-request.msg.html

(cl:defclass <Set_Robot_Model-request> (roslisp-msg-protocol:ros-message)
  ((model
    :reader model
    :initarg :model
    :type cl:string
    :initform ""))
)

(cl:defclass Set_Robot_Model-request (<Set_Robot_Model-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Set_Robot_Model-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Set_Robot_Model-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t2_package-srv:<Set_Robot_Model-request> is deprecated: use t2_package-srv:Set_Robot_Model-request instead.")))

(cl:ensure-generic-function 'model-val :lambda-list '(m))
(cl:defmethod model-val ((m <Set_Robot_Model-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-srv:model-val is deprecated.  Use t2_package-srv:model instead.")
  (model m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Set_Robot_Model-request>) ostream)
  "Serializes a message object of type '<Set_Robot_Model-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'model))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'model))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Set_Robot_Model-request>) istream)
  "Deserializes a message object of type '<Set_Robot_Model-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'model) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'model) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Set_Robot_Model-request>)))
  "Returns string type for a service object of type '<Set_Robot_Model-request>"
  "t2_package/Set_Robot_ModelRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Set_Robot_Model-request)))
  "Returns string type for a service object of type 'Set_Robot_Model-request"
  "t2_package/Set_Robot_ModelRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Set_Robot_Model-request>)))
  "Returns md5sum for a message object of type '<Set_Robot_Model-request>"
  "51cc362f6d06def3fd71b2dbe3614cc8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Set_Robot_Model-request)))
  "Returns md5sum for a message object of type 'Set_Robot_Model-request"
  "51cc362f6d06def3fd71b2dbe3614cc8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Set_Robot_Model-request>)))
  "Returns full string definition for message of type '<Set_Robot_Model-request>"
  (cl:format cl:nil "string model~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Set_Robot_Model-request)))
  "Returns full string definition for message of type 'Set_Robot_Model-request"
  (cl:format cl:nil "string model~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Set_Robot_Model-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'model))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Set_Robot_Model-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Set_Robot_Model-request
    (cl:cons ':model (model msg))
))
;//! \htmlinclude Set_Robot_Model-response.msg.html

(cl:defclass <Set_Robot_Model-response> (roslisp-msg-protocol:ros-message)
  ((robotID
    :reader robotID
    :initarg :robotID
    :type t2_package-msg:robot_id
    :initform (cl:make-instance 't2_package-msg:robot_id)))
)

(cl:defclass Set_Robot_Model-response (<Set_Robot_Model-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Set_Robot_Model-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Set_Robot_Model-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t2_package-srv:<Set_Robot_Model-response> is deprecated: use t2_package-srv:Set_Robot_Model-response instead.")))

(cl:ensure-generic-function 'robotID-val :lambda-list '(m))
(cl:defmethod robotID-val ((m <Set_Robot_Model-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-srv:robotID-val is deprecated.  Use t2_package-srv:robotID instead.")
  (robotID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Set_Robot_Model-response>) ostream)
  "Serializes a message object of type '<Set_Robot_Model-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'robotID) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Set_Robot_Model-response>) istream)
  "Deserializes a message object of type '<Set_Robot_Model-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'robotID) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Set_Robot_Model-response>)))
  "Returns string type for a service object of type '<Set_Robot_Model-response>"
  "t2_package/Set_Robot_ModelResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Set_Robot_Model-response)))
  "Returns string type for a service object of type 'Set_Robot_Model-response"
  "t2_package/Set_Robot_ModelResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Set_Robot_Model-response>)))
  "Returns md5sum for a message object of type '<Set_Robot_Model-response>"
  "51cc362f6d06def3fd71b2dbe3614cc8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Set_Robot_Model-response)))
  "Returns md5sum for a message object of type 'Set_Robot_Model-response"
  "51cc362f6d06def3fd71b2dbe3614cc8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Set_Robot_Model-response>)))
  "Returns full string definition for message of type '<Set_Robot_Model-response>"
  (cl:format cl:nil "t2_package/robot_id robotID~%~%~%================================================================================~%MSG: t2_package/robot_id~%Header header~%int8 id~%string model~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Set_Robot_Model-response)))
  "Returns full string definition for message of type 'Set_Robot_Model-response"
  (cl:format cl:nil "t2_package/robot_id robotID~%~%~%================================================================================~%MSG: t2_package/robot_id~%Header header~%int8 id~%string model~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Set_Robot_Model-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'robotID))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Set_Robot_Model-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Set_Robot_Model-response
    (cl:cons ':robotID (robotID msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Set_Robot_Model)))
  'Set_Robot_Model-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Set_Robot_Model)))
  'Set_Robot_Model-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Set_Robot_Model)))
  "Returns string type for a service object of type '<Set_Robot_Model>"
  "t2_package/Set_Robot_Model")