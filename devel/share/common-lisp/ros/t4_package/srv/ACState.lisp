; Auto-generated. Do not edit!


(cl:in-package t4_package-srv)


;//! \htmlinclude ACState-request.msg.html

(cl:defclass <ACState-request> (roslisp-msg-protocol:ros-message)
  ((active
    :reader active
    :initarg :active
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ACState-request (<ACState-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ACState-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ACState-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t4_package-srv:<ACState-request> is deprecated: use t4_package-srv:ACState-request instead.")))

(cl:ensure-generic-function 'active-val :lambda-list '(m))
(cl:defmethod active-val ((m <ACState-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t4_package-srv:active-val is deprecated.  Use t4_package-srv:active instead.")
  (active m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ACState-request>) ostream)
  "Serializes a message object of type '<ACState-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'active) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ACState-request>) istream)
  "Deserializes a message object of type '<ACState-request>"
    (cl:setf (cl:slot-value msg 'active) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ACState-request>)))
  "Returns string type for a service object of type '<ACState-request>"
  "t4_package/ACStateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ACState-request)))
  "Returns string type for a service object of type 'ACState-request"
  "t4_package/ACStateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ACState-request>)))
  "Returns md5sum for a message object of type '<ACState-request>"
  "d10b09b6bc031ed40715d35551db280c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ACState-request)))
  "Returns md5sum for a message object of type 'ACState-request"
  "d10b09b6bc031ed40715d35551db280c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ACState-request>)))
  "Returns full string definition for message of type '<ACState-request>"
  (cl:format cl:nil "bool active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ACState-request)))
  "Returns full string definition for message of type 'ACState-request"
  (cl:format cl:nil "bool active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ACState-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ACState-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ACState-request
    (cl:cons ':active (active msg))
))
;//! \htmlinclude ACState-response.msg.html

(cl:defclass <ACState-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ACState-response (<ACState-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ACState-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ACState-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t4_package-srv:<ACState-response> is deprecated: use t4_package-srv:ACState-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ACState-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t4_package-srv:result-val is deprecated.  Use t4_package-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ACState-response>) ostream)
  "Serializes a message object of type '<ACState-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ACState-response>) istream)
  "Deserializes a message object of type '<ACState-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ACState-response>)))
  "Returns string type for a service object of type '<ACState-response>"
  "t4_package/ACStateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ACState-response)))
  "Returns string type for a service object of type 'ACState-response"
  "t4_package/ACStateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ACState-response>)))
  "Returns md5sum for a message object of type '<ACState-response>"
  "d10b09b6bc031ed40715d35551db280c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ACState-response)))
  "Returns md5sum for a message object of type 'ACState-response"
  "d10b09b6bc031ed40715d35551db280c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ACState-response>)))
  "Returns full string definition for message of type '<ACState-response>"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ACState-response)))
  "Returns full string definition for message of type 'ACState-response"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ACState-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ACState-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ACState-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ACState)))
  'ACState-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ACState)))
  'ACState-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ACState)))
  "Returns string type for a service object of type '<ACState>"
  "t4_package/ACState")