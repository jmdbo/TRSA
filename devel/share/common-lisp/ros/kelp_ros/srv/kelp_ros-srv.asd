
(cl:in-package :asdf)

(defsystem "kelp_ros-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ServoControl" :depends-on ("_package_ServoControl"))
    (:file "_package_ServoControl" :depends-on ("_package"))
  ))