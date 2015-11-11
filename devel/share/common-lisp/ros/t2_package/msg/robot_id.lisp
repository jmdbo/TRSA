; Auto-generated. Do not edit!


(cl:in-package t2_package-msg)


;//! \htmlinclude robot_id.msg.html

(cl:defclass <robot_id> (roslisp-msg-protocol:ros-message)
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
   (model
    :reader model
    :initarg :model
    :type cl:string
    :initform ""))
)

(cl:defclass robot_id (<robot_id>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <robot_id>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'robot_id)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t2_package-msg:<robot_id> is deprecated: use t2_package-msg:robot_id instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <robot_id>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-msg:header-val is deprecated.  Use t2_package-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <robot_id>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-msg:id-val is deprecated.  Use t2_package-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'model-val :lambda-list '(m))
(cl:defmethod model-val ((m <robot_id>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-msg:model-val is deprecated.  Use t2_package-msg:model instead.")
  (model m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <robot_id>) ostream)
  "Serializes a message object of type '<robot_id>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'model))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'model))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <robot_id>) istream)
  "Deserializes a message object of type '<robot_id>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<robot_id>)))
  "Returns string type for a message object of type '<robot_id>"
  "t2_package/robot_id")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'robot_id)))
  "Returns string type for a message object of type 'robot_id"
  "t2_package/robot_id")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<robot_id>)))
  "Returns md5sum for a message object of type '<robot_id>"
  "5c2f9e6ea3b185d6a5046a4e13f05579")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'robot_id)))
  "Returns md5sum for a message object of type 'robot_id"
  "5c2f9e6ea3b185d6a5046a4e13f05579")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<robot_id>)))
  "Returns full string definition for message of type '<robot_id>"
  (cl:format cl:nil "Header header~%int8 id~%string model~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'robot_id)))
  "Returns full string definition for message of type 'robot_id"
  (cl:format cl:nil "Header header~%int8 id~%string model~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <robot_id>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4 (cl:length (cl:slot-value msg 'model))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <robot_id>))
  "Converts a ROS message object to a list"
  (cl:list 'robot_id
    (cl:cons ':header (header msg))
    (cl:cons ':id (id msg))
    (cl:cons ':model (model msg))
))
