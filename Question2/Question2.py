

def securitiesBuying(z, security_value):
   no_of_stocks=0
   z=int(z[0])
   #participants code here
   orders=[]
   for i in range(len(security_value)):
       orders.append((int(security_value[i]),i+1))
   orders.sort(key=lambda tup: tup[0])
   i=0
   while(z>0 and i<len(orders)):
       quantity=(int)(z/orders[i][0])
       quantity=min(orders[i][1],quantity)
       z-=quantity*orders[i][0]
       i+=1
       no_of_stocks+=quantity
    
    


   return no_of_stocks


def main():
    z= input().split()
    security_value = []
    security_value = input().split()
    no_of_stocks_purchased=securitiesBuying(z,security_value)
    print(no_of_stocks_purchased)




if __name__ == '__main__':
    main()
