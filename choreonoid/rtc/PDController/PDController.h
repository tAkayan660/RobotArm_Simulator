// -*- C++ -*-
/*!
 * @file  PDController.h
 * @brief PD Controller component
 * @date  $Date$
 *
 * $Id$
 */

#ifndef PDCONTROLLER_H
#define PDCONTROLLER_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>
#include <cnoid/MultiValueSeq>
#include <vector>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

using namespace RTC;

/*!
 * @class PDController
 * @brief PD Controller component
 *
 */
class PDController
: public RTC::DataFlowComponentBase
{
    public:
        /*!
         * @brief constructor
         * @param manager Maneger Object
         */
        PDController(RTC::Manager* manager);

        /*!
         * @brief destructor
         */
        ~PDController();

        // <rtc-template block="public_attribute">

        // </rtc-template>

        // <rtc-template block="public_operation">

        // </rtc-template>

        void ReadGain(size_t numJoints,std::vector<double> &pgain,std::vector<double> &dgain);

        /***
         *
         * The initialize action (on CREATED->ALIVE transition)
         * formaer rtc_init_entry() 
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        virtual RTC::ReturnCode_t onInitialize();

        /***
         *
         * The finalize action (on ALIVE->END transition)
         * formaer rtc_exiting_entry()
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onFinalize();

        /***
         *
         * The startup action when ExecutionContext startup
         * former rtc_starting_entry()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

        /***
         *
         * The shutdown action when ExecutionContext stop
         * former rtc_stopping_entry()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

        /***
         *
         * The activated action (Active state entry action)
         * former rtc_active_entry()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

        /***
         *
         * The deactivated action (Active state exit action)
         * former rtc_active_exit()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

        /***
         *
         * The execution action that is invoked periodically
         * former rtc_active_do()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

        /***
         *
         * The aborting action when main logic error occurred.
         * former rtc_aborting_entry()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

        /***
         *
         * The error action in ERROR state
         * former rtc_error_do()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

        /***
         *
         * The reset action that is invoked resetting
         * This is same but different the former rtc_init_entry()
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);

        /***
         *
         * The state update action that is invoked after onExecute() action
         * no corresponding operation exists in OpenRTm-aist-0.2.0
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

        /***
         *
         * The action that is invoked when execution context's rate is changed
         * no corresponding operation exists in OpenRTm-aist-0.2.0
         *
         * @param ec_id target ExecutionContext Id
         *
         * @return RTC::ReturnCode_t
         * 
         * 
         */
        // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


    protected:
        // <rtc-template block="protected_attribute">

        // </rtc-template>

        // <rtc-template block="protected_operation">

        // </rtc-template>

        // Configuration variable declaration
        // <rtc-template block="config_declare">

        // </rtc-template>

        // DataInPort declaration
        // <rtc-template block="inport_declare">
        RTC::TimedDoubleSeq m_angle;
        /*!
        */
        InPort<RTC::TimedDoubleSeq> m_angleIn;

        // </rtc-template>


        // DataOutPort declaration
        // <rtc-template block="outport_declare">
        RTC::TimedDoubleSeq m_torque;
        /*!
        */
        OutPort<RTC::TimedDoubleSeq> m_torqueOut;

        // </rtc-template>

        // CORBA Port declaration
        // <rtc-template block="corbaport_declare">

        // </rtc-template>

        // Service declaration
        // <rtc-template block="service_declare">

        // </rtc-template>

        // Consumer declaration
        // <rtc-template block="consumer_declare">

        // </rtc-template>

        private:
        std::vector<double> pgain;
        std::vector<double> dgain;
        std::vector<double> angleRef;
        std::vector<double> q_old;
        std::vector<double> q_old_ref;
        double dq_old;
        double dt; 
        double LinkAngle[5];
        // <rtc-template block="private_attribute">

        // </rtc-template>

        // <rtc-template block="private_operation">

        // </rtc-template>

};


extern "C"
{
    DLL_EXPORT void PDControllerInit(RTC::Manager* manager);
};

#endif // PDCONTROLLER_H
