A = input("Enter A: ")
b = input("Enter b: ")

n=size(A,1);



for k=1:n-1
    for i=k+1:n
        fa=A(i,k)/A(k,k);
        for j=k:n
            A(i,j)=A(i,j)-fa*A(k,j);
            disp(A(i,j))
        end
        b(i)=b(i)-fa*b(k);
        disp([A b])
    end
end

x(n)=b(n)/A(n,n);
for i=n-1:-1:1
    sum=0;
    for j=i+1:n
        sum=sum+A(i,j)*x(j);
    end
    x(i)=(b(i)-sum)/A(i,i);
end

disp(x)

