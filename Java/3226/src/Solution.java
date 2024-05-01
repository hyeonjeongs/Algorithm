import java.util.*;

class Solution {
    
    public Integer getTime(String data) {
        String[] times = data.split(":");
        int int_time = Integer.parseInt(times[0])*60 + Integer.parseInt(times[1]);
        return int_time;
    }
    
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        Map<Integer, Integer> cars = new HashMap<>();
        Map<Integer, Integer> out_cars = new HashMap<>();
        
        for(int i=0; i<records.length; i++) {
            String[] data = records[i].split(" ");
            Integer car_number = Integer.parseInt(data[1]);
            Integer current_time = getTime(data[0]);
            if(data[2].equals("IN")) {
                cars.put(car_number,current_time);
            }
            
            if(data[2].equals("OUT")) {
                Integer in_time = cars.get(car_number);
                Integer time = (current_time-in_time);
               
                if(out_cars.get(car_number)==null){
                    out_cars.put(car_number, time);
                } else {
                    out_cars.put(car_number, out_cars.get(car_number) + time);
                }
       
                cars.remove(car_number);
            }
        }
        
        for(Map.Entry<Integer, Integer> entry : cars.entrySet()) {
            Integer num= 23*60+59;
            Integer diffs = num- entry.getValue();
         
            if(out_cars.get(entry.getKey())==null){
                out_cars.put(entry.getKey(), diffs);
            } else {
             
                out_cars.put(entry.getKey(), diffs+out_cars.get(entry.getKey()));
            }
            
        }
        
        List<Integer> car_num = new ArrayList<Integer>();
        
        for(Map.Entry<Integer, Integer> entry : out_cars.entrySet()) {
            Integer key = entry.getKey();
          
            car_num.add(key);
            Integer diff= out_cars.get(key) - fees[0];
            if(diff <=0) {
                diff = 0;
            } else {
                diff = diff/fees[2];
            }
        
            if((out_cars.get(key) - fees[0])%fees[2] >0) {
                diff = diff +1;
            }
            Integer result = fees[1] + diff*fees[3];
            cars.put(key,result);
        }
        
        Collections.sort(car_num);
        answer = new int[car_num.size()];
        
        for(int i=0; i<car_num.size(); i++) {
            Integer index = car_num.get(i);
            answer[i] = cars.get(index);
        }
        
        return answer;
    }
}