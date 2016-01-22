; Auto-generated. Do not edit!


(cl:in-package kelp_ros-srv)


;//! \htmlinclude ServoControl-request.msg.html

(cl:defclass <ServoControl-request> (roslisp-msg-protocol:ros-message)
  ((axis
    :reader axis
    :initarg :axis
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 3 :element-type 'cl:boolean :initial-element cl:nil))
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass ServoControl-request (<ServoControl-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ServoControl-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ServoControl-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kelp_ros-srv:<ServoControl-request> is deprecated: use kelp_ros-srv:ServoControl-request instead.")))

(cl:ensure-generic-function 'axis-val :lambda-list '(m))
(cl:defmethod axis-val ((m <ServoControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kelp_ros-srv:axis-val is deprecated.  Use kelp_ros-srv:axis instead.")
  (axis m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <ServoControl-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kelp_ros-srv:angle-val is deprecated.  Use kelp_ros-srv:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ServoControl-request>) ostream)
  "Serializes a message object of type '<ServoControl-request>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'axis))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ServoControl-request>) istream)
  "Deserializes a message object of type '<ServoControl-request>"
  (cl:setf (cl:slot-value msg 'axis) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'axis)))
    (cl:dotimes (i 3)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream))))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ServoControl-request>)))
  "Returns string type for a service object of type '<ServoControl-request>"
  "kelp_ros/ServoControlRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoControl-request)))
  "Returns string type for a service object of type 'ServoControl-request"
  "kelp_ros/ServoControlRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ServoControl-request>)))
  "Returns md5sum for a message object of type '<ServoControl-request>"
  "72af5ec18b305597075cd2db6d215c26")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ServoControl-request)))
  "Returns md5sum for a message object of type 'ServoControl-request"
  "72af5ec18b305597075cd2db6d215c26")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ServoControl-request>)))
  "Returns full string definition for message of type '<ServoControl-request>"
  (cl:format cl:nil "bool[3] axis~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ServoControl-request)))
  "Returns full string definition for message of type 'ServoControl-request"
  (cl:format cl:nil "bool[3] axis~%float32 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ServoControl-request>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'axis) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ServoControl-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ServoControl-request
    (cl:cons ':axis (axis msg))
    (cl:cons ':angle (angle msg))
))
;//! \htmlinclude ServoControl-response.msg.html

(cl:defclass <ServoControl-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ServoControl-response (<ServoControl-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ServoControl-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ServoControl-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kelp_ros-srv:<ServoControl-response> is deprecated: use kelp_ros-srv:ServoControl-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ServoControl-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kelp_ros-srv:result-val is deprecated.  Use kelp_ros-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ServoControl-response>) ostream)
  "Serializes a message object of type '<ServoControl-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ServoControl-response>) istream)
  "Deserializes a message object of type '<ServoControl-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ServoControl-response>)))
  "Returns string type for a service object of type '<ServoControl-response>"
  "kelp_ros/ServoControlResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoControl-response)))
  "Returns string type for a service object of type 'ServoControl-response"
  "kelp_ros/ServoControlResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ServoControl-response>)))
  "Returns md5sum for a message object of type '<ServoControl-response>"
  "72af5ec18b305597075cd2db6d215c26")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ServoControl-response)))
  "Returns md5sum for a message object of type 'ServoControl-response"
  "72af5ec18b305597075cd2db6d215c26")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ServoControl-response>)))
  "Returns full string definition for message of type '<ServoControl-response>"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ServoControl-response)))
  "Returns full string definition for message of type 'ServoControl-response"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ServoControl-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ServoControl-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ServoControl-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ServoControl)))
  'ServoControl-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ServoControl)))
  'ServoControl-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ServoControl)))
  "Returns string type for a service object of type '<ServoControl>"
  "kelp_ros/ServoControl")