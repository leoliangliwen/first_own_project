#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Observer
{
  public:
    virtual void update(float temp, float humidity) = 0;
};

class Subject
{
  public:
    virtual void registerObserver(Observer *observerIn) = 0;
    virtual void removeObserver(Observer *observerIn) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherData: public Subject
{
    set<Observer *> observers;
    float temperature;
    float humidity;
    bool changed;

  public:
    float getTemperature() {return temperature;}
    float getHumidity() {return humidity;}
    void setMeasurements(float temperatureIn, float humidityIn) 
    {
        temperature = temperatureIn;
        humidity = humidityIn;
        measurementsChanged();
        changed = true;
    }
    void measurementsChanged() {notifyObservers();}

    void registerObserver(Observer *observerIn) {observers.insert(observerIn);}
    void removeObserver(Observer *observerIn) {observers.erase(observerIn);}
    void notifyObservers() 
    {
        for (auto it = observers.begin(); it != observers.end(); it++)
        {
            (*it)->update(temperature, humidity);
        }
        changed = false;
    }
};

class DisplayElement
{
  public:
    virtual void display() = 0;
};

class CurrentConditionsDisplay: public Observer, public DisplayElement
{
    Subject* subject;
    float temperature;
    float humidity;

  public:
    CurrentConditionsDisplay(Subject* subjectIn)
    {
        subject = subjectIn;
        subjectIn->registerObserver(this);
    }
    void update(float temperatureIn, float humidityIn) 
    {
        temperature = temperatureIn;
        humidity = humidityIn;
        display();
    }
    void display() 
    {
        cout << "Displaying in CurrentConditionDisplay:\n" 
             << "Temperature: " << temperature 
             << ", Humidity: " << humidity << endl << endl;
    }
};

class StatisticsDisplay: public Observer, public DisplayElement
{
    Subject* subject;
    vector<float> temperature;
    vector<float> humidity;

  public:
    StatisticsDisplay(Subject* subjectIn)
    {
        subject = subjectIn;
        subjectIn->registerObserver(this);
    }
    void update(float temperatureIn, float humidityIn) 
    {
        temperature.push_back(temperatureIn);
        humidity.push_back(humidityIn);
        display();
    }
    void display() 
    {
        cout << "Displaying in StatisticsDisplay:\n";
        cout << "Temperature: "; 
        for (auto i = temperature.begin(); i != temperature.end(); i++)
        {
            cout << *i << ", ";
        }
        cout << "humidity: "; 
        for (auto i = humidity.begin(); i != humidity.end(); i++)
        {
            cout << *i << ", ";
        }
        cout << endl << endl;
    }
};

class NewDisplay: public Observer, public DisplayElement
{
    Subject* subject;
    float temperature;
    float humidity;

  public:
    NewDisplay(Subject* subjectIn)
    {
        subject = subjectIn;
        subjectIn->registerObserver(this);
    }
    void update(float temperatureIn, float humidityIn) 
    {
        temperature = temperatureIn;
        humidity = humidityIn;
        display();
    }
    void display() 
    {
        cout << "Displaying in NewDisplay:\n" 
             << "Temperature: " << temperature 
             << ", Humidity: " << humidity << endl << endl;
    }
};

int main ()
{
    WeatherData weatherData;
    
    CurrentConditionsDisplay currentConditionsDisplay(&weatherData);
    StatisticsDisplay statisticsDisplay(&weatherData);
    NewDisplay newDisplay(&weatherData);

    weatherData.setMeasurements(1.0, 2.0);
    weatherData.setMeasurements(11.0, 22.0);
    return 1;
}


















