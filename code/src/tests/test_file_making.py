#!/usr/bin/python
# -*- coding: utf-8 -*-

import psycopg2
import psycopg2.extras
import sys
import math
import random

args=(sys.argv);
print args
file_name=args[1];
print file_name
try:
    cs="dbname=%s user=%s" % (file_name,'postgres')
    print cs
    con = psycopg2.connect(cs)         
    cursor = con.cursor(cursor_factory=psycopg2.extras.DictCursor)
    cursor.execute("SELECT * FROM ways_vertices_pgr order by id")   
    vertex_row = cursor.fetchall()

except psycopg2.DatabaseError, e:
    print 'Error %s' % e    
    sys.exit(1)

finally:
    
    if con:
        con.close()
    total=501
    count1=0;
    count2=0;
    count3=0;
    count4=0;
    count5=0;
    f1=open('./'+file_name+'/range1','a')
    f2=open('./'+file_name+'/range2','a')
    f3=open('./'+file_name+'/range3','a')
    f4=open('./'+file_name+'/range4','a')
    f5=open('./'+file_name+'/range5','a')
    low=1
    high=len(vertex_row)
    while 1:
        r1=random.randint(low,high-1)
        r2=random.randint(low,high-1)
        #print vertex_row[r1]["id"];
        x1=vertex_row[r1]["lon"]
        x2=vertex_row[r2]["lon"]
        y1=vertex_row[r1]["lat"]
        y2=vertex_row[r2]["lat"]
        diff=math.sqrt(pow(x2-x1,2)+pow(y2-y1,2))*1000
        print diff
        if diff>1 and diff<5 and count1<total:
            count1=count1+1
            str1=str(vertex_row[r1]["id"])+' '+str(vertex_row[r2]["id"])+'\n'
            f1.write(str1)
        elif diff>5 and diff<10 and count2<total:
            count2=count2+1
            str1=str(vertex_row[r1]["id"])+' '+str(vertex_row[r2]["id"])+'\n'
            f2.write(str1)
        elif diff>10 and diff<15 and count3<total:
            count3=count3+1
            str1=str(vertex_row[r1]["id"])+' '+str(vertex_row[r2]["id"])+'\n'
            f3.write(str1)
        elif diff>15 and diff<20 and count4<total:
            count4=count4+1
            str1=str(vertex_row[r1]["id"])+' '+str(vertex_row[r2]["id"])+'\n'
            f4.write(str1)
        else:
            if count5<total:
                count5=count5+1
                str1=str(vertex_row[r1]["id"])+' '+str(vertex_row[r2]["id"])+'\n'
                f5.write(str1)
        if count1==total and count2==total and count3==total and count4==total and count5==total:
            break
        
            
        
            
            
            
            
       
            
        
        
        
        