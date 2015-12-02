
(cl:in-package :asdf)

(defsystem "t8_package-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "thermal_msg" :depends-on ("_package_thermal_msg"))
    (:file "_package_thermal_msg" :depends-on ("_package"))
    (:file "cup_info" :depends-on ("_package_cup_info"))
    (:file "_package_cup_info" :depends-on ("_package"))
  ))