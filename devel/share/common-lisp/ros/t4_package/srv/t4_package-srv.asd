
(cl:in-package :asdf)

(defsystem "t4_package-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SetTemperature" :depends-on ("_package_SetTemperature"))
    (:file "_package_SetTemperature" :depends-on ("_package"))
    (:file "DesiredTemperature" :depends-on ("_package_DesiredTemperature"))
    (:file "_package_DesiredTemperature" :depends-on ("_package"))
    (:file "ACState" :depends-on ("_package_ACState"))
    (:file "_package_ACState" :depends-on ("_package"))
  ))