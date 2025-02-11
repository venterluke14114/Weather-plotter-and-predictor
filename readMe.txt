Weather Data Analysis and Prediction Toolkit
Overview
This command-line toolkit processes and analyzes weather data, allowing users to compute yearly candlestick representations, visualize data in text format, apply filtering based on user-defined criteria, and predict future temperature trends using linear regression. The program reads temperature data from a CSV file, extracts relevant country-specific information, and provides a structured way to interpret and forecast climate trends.

Features
Compute Candlestick Data – Aggregates yearly temperature data into a structured format with Open, Close, High, and Low values.
Text-Based Plotting – Displays temperature trends using an ASCII candlestick representation for visualization in the terminal.
Data Filtering – Allows filtering of data by year range and temperature range for refined analysis.
Linear Regression Prediction – Uses historical data to predict future temperature trends for a user-specified range of years.

How It Works
Data Processing

Reads hourly temperature data from a CSV file.
Identifies the relevant column based on a country code (e.g., GB_temperature).
Aggregates data into yearly candlestick format.
Visualization

Generates a text-based plot where | represents High and Low, and [ and ] indicate Open and Close temperatures.
Dynamically adjusts scaling to fit terminal width.
Filtering

Users specify a date range and temperature limits.
The program removes candlesticks that do not meet the criteria.
Prediction

A linear regression model calculates the slope and intercept based on historical temperature trends.
Predicts temperatures for future years based on past data trends.
Example Output
yaml
Copy
Edit
    |                |
    |    [      ]    |
    |________________|
  -3.612             23.054
   1980
java
Copy
Edit
Year 2021: predicted avg temperature = 9.79252
Year 2022: predicted avg temperature = 9.80776
Future Improvements
Support for monthly and daily candlestick aggregation.
 Advanced machine learning models for better prediction accuracy.
Exporting plots and predictions to files for further analysis.

Usage
To run the program, compile all .cpp files and execute the binary:

bash
Copy
Edit
g++ -o weather_app main.cpp Candlestick.cpp WeatherDataProcessor.cpp WeatherDataFilter.cpp TextPlot.cpp WeatherDataPredictor.cpp
./weather_app
The user will then be prompted to enter filtering and prediction parameters.

This project provides a lightweight, text-based alternative for weather trend analysis, offering a clear and structured approach to historical and future temperature visualization.
