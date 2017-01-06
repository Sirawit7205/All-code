clear;
clc;
x= input('Enter number: ');
if x>0
    y=log(x)
else
    beep;
    disp('The input to the log function must be positive.')
end