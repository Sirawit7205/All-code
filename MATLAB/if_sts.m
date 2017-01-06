N=3;
for k=1:N
    for m=1:N
        if k<m
            A(k,m)=3;
        elseif k==m
            A(k,m)=2;
        else
            A(k,m)=1;
        end
    end
end
disp(A)