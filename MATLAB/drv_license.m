clear;
clc;
x= input('Enter age: ');
if x<=0 || x>100
    disp('Invalid input.')
elseif x<18
    disp('Sorry, you will have to wait.')
elseif x<25
    disp('You may have a young license.')
elseif x<60
    disp('You may have a standard license.')
elseif x>60
    disp('Drivers over 60 require a special license.')
end