; Auto-generated. Do not edit!


(cl:in-package t8_package-msg)


;//! \htmlinclude thermal_msg.msg.html

(cl:defclass <thermal_msg> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0)
   (temp
    :reader temp
    :initarg :temp
    :type cl:fixnum
    :initform 0))
)

(cl:defclass thermal_msg (<thermal_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <thermal_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'thermal_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t8_package-msg:<thermal_msg> is deprecated: use t8_package-msg:thermal_msg instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <thermal_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:header-val is deprecated.  Use t8_package-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <thermal_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:id-val is deprecated.  Use t8_package-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'temp-val :lambda-list '(m))
(cl:defmethod temp-val ((m <thermal_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t8_package-msg:temp-val is deprecated.  Use t8_package-msg:temp instead.")
  (temp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <thermal_msg>) ostream)
  "Serializes a message object of type '<thermal_msg>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'temp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <thermal_msg>) istream)
  "Deserializes a message object of type '<thermal_msg>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'temp) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<thermal_msg>)))
  "Returns string type for a message object of type '<thermal_msg>"
  "t8_package/thermal_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'thermal_msg)))
  "Returns string type for a message object of type 'thermal_msg"
  "t8_package/thermal_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<thermal_msg>)))
  "Returns md5sum for a message object of type '<thermal_msg>"
  "a39aa23240fd1bc7d31d54704ff73af1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'thermal_msg)))
  "Returns md5sum for a message object of type 'thermal_msg"
  "a39aa23240fd1bc7d31d54704ff73af1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<thermal_msg>)))
  "Returns full string definition for message of type '<thermal_msg>"
  (cl:format cl:nil "Header header~%int8 id~%int8 temp~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'thermal_msg)))
  "Returns full string definition for message of type 'thermal_msg"
  (cl:format cl:nil "Header header~%int8 id~%int8 temp~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <thermal_msg>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <thermal_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'thermal_msg
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':temp (temp msg))
))
