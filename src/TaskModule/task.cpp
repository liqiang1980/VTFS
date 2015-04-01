#include "task.h"

#define initP_x 0.28
#define initP_y 0.3
#define initP_z 0.30

#define initO_x 0.0
#define initO_y M_PI/2;
#define initO_z 0.0;

Task::Task()
{
    desired_p_eigen(0) = -1 * initP_x;
    desired_p_eigen(1) = initP_y;
    desired_p_eigen(2) = initP_z;
    desired_o_ax(0) = initO_x;
    desired_o_ax(1) = initO_y;
    desired_o_ax(2) = initO_z;
    curtaskname.tact = CONTACT_FORCE_TRACKING;
    curtaskname.prot = RP_NOCONTROL;
    mt = JOINTS;
    mft = GLOBAL;
    velocity_p2p.setZero();
}
