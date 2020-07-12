#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Observer
{
  public:
    virtual void update(float temp, float humidity) = 0;
};

class WeatherData
{
    set<Observer *> observers;
    float temperature;
    float humidity;

  public:
    float getTemperature() {return temperature;}
    float getHumidity() {return humidity;}
    void setMeasurements(float temperatureIn, float humidityIn) 
    {
        temperature = temperatureIn;
        humidity = humidityIn;
        measurementsChanged();
    }
    void measurementsChanged() {notifyObservers();}

    void registerObserver(Observer *observerIn) {observers.insert(observerIn);}
    void removeObserver(Observer *observerIn) {observers.erase(observerIn);}
    void notifyObservers() 
    {
        cout << "Start display=================" << endl;
        for (auto it = observers.begin(); it != observers.end(); it++)
        {
            (*it)->update(temperature, humidity);
        }
        cout << "End display" << endl << endl << endl;
    }
};

class DisplayElement
{
  public:
    virtual void display() = 0;
};

class CurrentDisplay: public Observer, public DisplayElement
{
    WeatherData* subject;
    float temperature;
    float humidity;

  public:
    CurrentDisplay(WeatherData* subjectIn)
    {
        subject = subjectIn;
        subject->registerObserver(this);
    }
    ~CurrentDisplay()
    {
        subject->removeObserver(this);
    }
    void update(float temperatureIn, float humidityIn) 
    {
        temperature = temperatureIn;
        humidity = humidityIn;
        display();
    }
    void display() 
    {
        cout << "\nDisplaying in CurrentWeatherDisplay:\n" 
             << "Temperature: " << temperature 
             << ", Humidity: " << humidity << endl << endl;
    }
};

class HistoryWeatherDisplay: public Observer, public DisplayElement
{
    WeatherData* subject;
    vector<float> temperatures;
    vector<float> humiditys;

  public:
    HistoryWeatherDisplay(WeatherData* subjectIn)
    {
        subject = subjectIn;
        subject->registerObserver(this);
    }
    ~HistoryWeatherDisplay()
    {
        subject->removeObserver(this);
    }
    void update(float temperatureIn, float humidityIn) 
    {
        temperatures.push_back(temperatureIn);
        humiditys.push_back(humidityIn);
        display();
    }
    void display() 
    {
        cout << "\nDisplaying in HistoryWeatherDisplay:\n";
        cout << "Temperature: "; 
        for (auto i = temperatures.begin(); i != temperatures.end(); i++)
        {
            cout << *i << ", ";
        }
        cout << "humidity: "; 
        for (auto i = humiditys.begin(); i != humiditys.end(); i++)
        {
            cout << *i << ", ";
        }
        cout << endl << endl;
    }
};

class ForecastDisplay: public Observer, public DisplayElement
{
    WeatherData* subject;
    vector<float> temperatures;
    vector<float> humiditys;

  public:
    ForecastDisplay(WeatherData* subjectIn)
    {
        subject = subjectIn;
        subject->registerObserver(this);
    }
    ~ForecastDisplay()
    {
        subject->removeObserver(this);
    }
    void update(float temperatureIn, float humidityIn) 
    {
        temperatures.push_back(temperatureIn);
        humiditys.push_back(humidityIn);
        display();
    }
    void display() 
    {
        int size = temperatures.size();
        if (size == 1) {
            cout << "\nDisplaying in ForecastWeatherDisplay:\n" 
                << "Temperature: " << temperatures[0]
                << ", Humidity: " << humiditys[0] << endl << endl;
        }
        else {
            float temperatureforecast = temperatures[size-1] + 
                                        temperatures[size-1] - 
                                        temperatures[size-2];
            float humidityforecast = humiditys[size-1] + 
                                     humiditys[size-1] - 
                                     humiditys[size-2];
            cout << "\nDisplaying in ForecastWeatherDisplay:\n" 
                << "Temperature: " << temperatureforecast
                << ", Humidity: " << humidityforecast << endl << endl;
        }
    }
};

int main ()
{
    WeatherData weatherData;
    
    CurrentDisplay currentDisplay(&weatherData);
    HistoryWeatherDisplay historyDisplay(&weatherData);
    ForecastDisplay forecastDisplay(&weatherData);

    weatherData.setMeasurements(1.0, 1.0);
    weatherData.setMeasurements(2.0, 2.0);
    weatherData.setMeasurements(5.0, 5.0);
    return 1;
}


















