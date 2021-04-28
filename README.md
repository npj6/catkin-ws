Instructions
==========

Remember to ``source devel/setup.bash`` in each terminal you open. This should be done inside the project's root folder ``catkin_ws``.

To build all the modules, use ``catkin_make``.

The following list contains each module and the command to start it up:

* VAR control (main module): ``rosrun var_ctrl var_ctrl``
* ejemplogazebo (gazebo race circuit): ``roslaunch ejemplogazebo create_multi_robot.launch``
* load\_model (gazebo room): ``roslaunch load_model init.launch``

The following list contains the turtlebot names for each gazebo scene:

* ejemplogazebo: robot1, robot2
* load\_model: _none (code has been accomodated to ignore empty robot names)_

ejemplogazebo's turtlebots include two back cameras with the names **trasera1** and **trasera2**
