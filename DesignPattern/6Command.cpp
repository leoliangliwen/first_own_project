#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Command
{
  public:
      virtual void execute() = 0;
      virtual void undo() = 0;
      virtual ~Command(){};
};

class NoImplementCommand : public Command
{
  public:
      void execute() {cout << "This button is not implemented.\n";}
      void undo() {cout << "This button is not implemented.\n";}
};

static NoImplementCommand noImplementCommand;

class Light
{
  public:
      void on() {cout << "light is turned on.\n";}
      void off() {cout << "light is turned off.\n";}
};

class LightOnCommand: public Command
{
    Light light;
  public:
    LightOnCommand(Light &lightIn) : light(lightIn){} 
    void execute() {light.on();}
    void undo() {light.off();}
};

class LightOffCommand: public Command
{
    Light light;
  public:
    LightOffCommand(Light &lightIn) : light(lightIn){} 
    void execute() {light.off();}
    void undo() {light.on();}
};

class Door 
{
  public:
      void open() {cout << "door is opened.\n";}
      void close() {cout << "door is closed.\n";}
};

class DoorOpenCommand: public Command
{
    Door door;
  public:
    DoorOpenCommand(Door &doorIn) : door(doorIn){} 
    void execute() {door.open();}
    void undo() {door.close();}
};

class DoorCloseCommand: public Command
{
    Door door;
  public:
    DoorCloseCommand(Door &doorIn) : door(doorIn){} 
    void execute() {door.close();}
    void undo() {door.open();}
};

class MacroCommand: public Command
{
    vector<Command*> commands;
  public:
    MacroCommand(vector<Command*> commandsIn) : commands(commandsIn){};
    void execute() 
    {
        for (auto c : commands)
            c->execute();
    }
    void undo()
    {
        for (auto c : commands)
            c->undo();
    }
};

class RemoteControl
{
    vector<Command*> on_slots;
    vector<Command*> off_slots;
    Command* lastCommand = nullptr;

  public:
    RemoteControl() 
        : on_slots(10, &noImplementCommand),
          off_slots(10, &noImplementCommand) {}

    void setCommand(int slot, Command* commandOn, Command* commandOff) 
    {
        if (slot >= 10)
            return;
        on_slots[slot] = commandOn;
        off_slots[slot] = commandOff;
    }

    void pressOnButton(int slot) 
    {
        on_slots[slot]->execute();
        lastCommand = on_slots[slot];
    }
    void pressOffButton(int slot) 
    {
        off_slots[slot]->execute();
        lastCommand = off_slots[slot];
    }

    void undo() {
        cout << "Undo star\n";
        if (lastCommand != nullptr )
            lastCommand->undo();
        else
            cout << "Nothing to undo.\n";
        cout << "Undo finish\n";
    }

};

int main ()
{
    RemoteControl control;

    Light light;
    LightOnCommand lightOnCommand(light);
    LightOffCommand lightOffCommand(light);
    control.setCommand(0, &lightOnCommand, &lightOffCommand);

    Door door;
    DoorOpenCommand doorOpenCommand(door);
    DoorCloseCommand doorCloseCommand(door);
    control.setCommand(1, &doorOpenCommand, &doorCloseCommand);

    MacroCommand partyStar({&lightOnCommand, &doorOpenCommand});
    MacroCommand partyClose({&lightOffCommand, &doorCloseCommand});
    control.setCommand(2, &partyStar, &partyClose);
    control.pressOnButton(2);
    control.undo();


    /*
    control.undo();
    control.pressOnButton(0);
    control.undo();
    control.pressOnButton(1);
    control.pressOffButton(0);
    control.pressOffButton(1);
    control.undo();
    control.pressOffButton(4);
    */
    return 1;
}
