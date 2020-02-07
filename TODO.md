# TO DO
- Build Drive station with VS Code, WPIlibs, NavX, Phoenix, etc.
- Check that all Talons and Victors have latest firmware
- Give driver station a static IP configuration.

        IP: 10.61.53.5
        Subnet Mask: 255.0.0.0
        Gateway: 10.61.53.1

- Give your RIO a static IP configuration.

        IP: “10.61.53.2”
        Subnet Mask: 255.255.255.0 <- NOTE THE DIFFERENCE HERE
        Gateway: 10.61.53.1

- (Done) Give your Limelights unique static IP configurations.

        IP: “10.61.53.11”
        Subnet mask: 255.255.255.0
        Gateway: “10.61.53.1”

## High Priority
- Intake(Sol)
    - Intake Motor
    - Intake Solenoid(x2?)
    - Command Group
- Ball Magazine(Lucien) 
    - Solenoid
    - Motor(x2?)
    - Indexer
- Ball Shooter Velocity and PID(Cameron)
    - Change Motor Speed using equation
    - Vision targeting getting distance(Create Pipeline)
- Ball Vision Targeting(Cameron) 
    - Create Pipeline for ball
    - Switch between pipelines
- Color Sensor(Lucien) 
    - Motor
    - Color Sensor working
    - Find update speed and how fast the wheel needs to move
    - Create Equation/Counting for spinning wheel 4 times
    - Create Equation/Counting for selecting correct color
- Make Drive System good(Lucien)
    - PID tuning
    - Create if statement for auto
- NavX(Lucien)
    - Calculate values that need to be used
- Autonomous(Lucien)
    - Pass NavX values into Autonomous command
    - Use NavX to control when commands finish when the robot has traveled a specified distance
## Low Priority
- Flashy Lights to communicate if we are alligned


