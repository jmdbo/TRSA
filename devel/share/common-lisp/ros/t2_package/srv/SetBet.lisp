; Auto-generated. Do not edit!


(cl:in-package t2_package-srv)


;//! \htmlinclude SetBet-request.msg.html

(cl:defclass <SetBet-request> (roslisp-msg-protocol:ros-message)
  ((player_id
    :reader player_id
    :initarg :player_id
    :type cl:fixnum
    :initform 0)
   (bet
    :reader bet
    :initarg :bet
    :type cl:fixnum
    :initform 0))
)

(cl:defclass SetBet-request (<SetBet-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetBet-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetBet-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t2_package-srv:<SetBet-request> is deprecated: use t2_package-srv:SetBet-request instead.")))

(cl:ensure-generic-function 'player_id-val :lambda-list '(m))
(cl:defmethod player_id-val ((m <SetBet-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-srv:player_id-val is deprecated.  Use t2_package-srv:player_id instead.")
  (player_id m))

(cl:ensure-generic-function 'bet-val :lambda-list '(m))
(cl:defmethod bet-val ((m <SetBet-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-srv:bet-val is deprecated.  Use t2_package-srv:bet instead.")
  (bet m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetBet-request>) ostream)
  "Serializes a message object of type '<SetBet-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'player_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bet)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetBet-request>) istream)
  "Deserializes a message object of type '<SetBet-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'player_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bet)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetBet-request>)))
  "Returns string type for a service object of type '<SetBet-request>"
  "t2_package/SetBetRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetBet-request)))
  "Returns string type for a service object of type 'SetBet-request"
  "t2_package/SetBetRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetBet-request>)))
  "Returns md5sum for a message object of type '<SetBet-request>"
  "5d93a0c5d016c9a6bcb0a3b38a993147")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetBet-request)))
  "Returns md5sum for a message object of type 'SetBet-request"
  "5d93a0c5d016c9a6bcb0a3b38a993147")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetBet-request>)))
  "Returns full string definition for message of type '<SetBet-request>"
  (cl:format cl:nil "uint8 player_id~%uint8 bet~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetBet-request)))
  "Returns full string definition for message of type 'SetBet-request"
  (cl:format cl:nil "uint8 player_id~%uint8 bet~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetBet-request>))
  (cl:+ 0
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetBet-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetBet-request
    (cl:cons ':player_id (player_id msg))
    (cl:cons ':bet (bet msg))
))
;//! \htmlinclude SetBet-response.msg.html

(cl:defclass <SetBet-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass SetBet-response (<SetBet-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetBet-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetBet-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name t2_package-srv:<SetBet-response> is deprecated: use t2_package-srv:SetBet-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <SetBet-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader t2_package-srv:result-val is deprecated.  Use t2_package-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetBet-response>) ostream)
  "Serializes a message object of type '<SetBet-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetBet-response>) istream)
  "Deserializes a message object of type '<SetBet-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetBet-response>)))
  "Returns string type for a service object of type '<SetBet-response>"
  "t2_package/SetBetResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetBet-response)))
  "Returns string type for a service object of type 'SetBet-response"
  "t2_package/SetBetResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetBet-response>)))
  "Returns md5sum for a message object of type '<SetBet-response>"
  "5d93a0c5d016c9a6bcb0a3b38a993147")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetBet-response)))
  "Returns md5sum for a message object of type 'SetBet-response"
  "5d93a0c5d016c9a6bcb0a3b38a993147")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetBet-response>)))
  "Returns full string definition for message of type '<SetBet-response>"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetBet-response)))
  "Returns full string definition for message of type 'SetBet-response"
  (cl:format cl:nil "bool result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetBet-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetBet-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetBet-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetBet)))
  'SetBet-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetBet)))
  'SetBet-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetBet)))
  "Returns string type for a service object of type '<SetBet>"
  "t2_package/SetBet")