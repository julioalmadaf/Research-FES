%Set Routine Parameters
%Right 1 (closing hand)
maxRight1 = 10;
counterRight1 = 0;

%Left 1 (closing hand)
maxLeft1 = 10;
counterLeft1 = 0;

%Right 2 (Wrist Extension)
maxRight2 = 17;
counterRight2 = 0;

%Left 2 (Wrist Extension)
maxLeft2 = 17;
counterLeft2 = 0;

%Right 3 (Radial Deviation)
maxRight3 = 12;
counterRight3 = 0;

%Left 3 (Radial Deviation)
maxLeft3 = 12;
counterLeft3 = 0;


%number of times the movement is done
repeticiones = 2; 
repcounter = 0;


%Change channel 1 Frequency(for right hand)
ans.setFreqSingle(1,30);


%Change channel 2 Frequency(for left hand)
ans.setFreqSingle(2,30);

%Description of the first routine is the same for the other routines
%Routine Execution(Right1)
%Reset of the repetition counter(Reptitions of each routine)
    repcounter=0; 
    %It wont stop until the repetion counter is met and the max amplitude
    %is met
    while  (counterRight1 < maxRight1) && (repcounter < repeticiones)
        %Counter of amplitude increases by .1 
        counterRight1 = counterRight1+.1;
        %It sends the new amplitude through the first channel, 300Hz
        ans.setAmpPwidthSingle(1,counterRight1,300);
        %The routine waits for .1 seconds
        pause(.1); 
        %When the max amplitude is met
        if counterRight1 >= maxRight1
            %the repetition counter increases
            repcounter = repcounter + 1; 
            %The amplitude decreases by .1 each .1 seconds
            while counterRight1 > 0 
                counterRight1 = counterRight1 - .1;
                %The amplitude is sent through the first channel, 300Hz
                ans.setAmpPwidthSingle(1,counterRight1,300);
                pause (.1);
            end
        end
    end
   
    %Routine Execution(Right2)
    repcounter=0; 
    while  (counterRight2 < maxRight2) && (repcounter < repeticiones)
        counterRight2 = counterRight2+.1;
        ans.setAmpPwidthSingle(1,counterRight2,300);
        pause(.1); 
        
        if counterRight2 >= maxRight2
            repcounter = repcounter + 1; 
            while counterRight2 > 0 
                counterRight2 = counterRight2 - .1;
                ans.setAmpPwidthSingle(1,counterRight2,300);
                pause (.1);
            end
        end
    end
    
    %Routine Execution(Right3)
    repcounter=0;
    while  (counterRight3 < maxRight3) && (repcounter < repeticiones)
        counterRight3 = counterRight3+.1;
        ans.setAmpPwidthSingle(1,counterRight3,300);
        pause(.1); 
        
        if counterRight3 >= maxRight3
            repcounter = repcounter + 1; 
            while counterRight3 > 0 
                counterRight3 = counterRight3 - .1;
                ans.setAmpPwidthSingle(1,counterRight3,300);
                pause (.1);
            end
        end
    end
    

%Routine Execution( Left 1)
    repcounter=0;
    while  (counterLeft1 < maxLeft1) && (repcounter < repeticiones)
        counterLeft1 = counterLeft1+.1;
        %For the Left movements tha channel configured is the second one(It
        %is not necessary
        ans.setAmpPwidthSingle(2,counterLeft1,300);
        pause(.1); 
        
        if counterLeft1 >= maxLeft1
            repcounter = repcounter + 1; 
            while counterLeft1 > 0 
                counterLeft1 = counterLeft1 - .1;
                ans.setAmpPwidthSingle(2,counterLeftt1,300);
                pause (.1);
            end
        end
    end
   
    %Routine Execution(Left 2)
    repcounter=0;
    while  (counterLeft2 < maxLeft2) && (repcounter < repeticiones)
        counterLeft2 = counterLeft2+.1;
        ans.setAmpPwidthSingle(2,counterLeft2,300);
        pause(.1); 
        
        if counterLeft2 >= maxLeft2
            repcounter = repcounter + 1; 
            while counterLeft2 > 0 
                counterLeft2 = counterLeft2 - .1;
                ans.setAmpPwidthSingle(2,counterLeft2,300);
                pause (.1);
            end
        end
    end
    
    %Routine Execution(Left 3)
    repcounter=0;
    while  (counterLeft3 < maxLeft3) && (repcounter < repeticiones)
        counterLeft3 = counterLeft3+.1;
        ans.setAmpPwidthSingle(2,counterLeft3,300);
        pause(.1); 
        
        if counterLeft3 >= maxLeft3
            repcounter = repcounter + 1; 
            while counterLeft3 > 0 
                counterLeft3 = counterLeft3 - .1;
                ans.setAmpPwidthSingle(2,counterLeft3,300);
                pause (.1);
            end
        end
    end
    
    