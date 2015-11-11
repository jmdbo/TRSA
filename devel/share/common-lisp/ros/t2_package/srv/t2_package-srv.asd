
(cl:in-package :asdf)

(defsystem "t2_package-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :t2_package-msg
)
  :components ((:file "_package")
    (:file "Set_Robot_Model" :depends-on ("_package_Set_Robot_Model"))
    (:file "_package_Set_Robot_Model" :depends-on ("_package"))
    (:file "SetBet" :depends-on ("_package_SetBet"))
    (:file "_package_SetBet" :depends-on ("_package"))
    (:file "Activate" :depends-on ("_package_Activate"))
    (:file "_package_Activate" :depends-on ("_package"))
  ))