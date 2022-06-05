/*
 *
 * 
 * 
 */


import java.util.List;
import java.lang.Math;


public class RR implements Algorithm {
    

    private List<Task> queue;
    private int quantum = 25;

    public RR(List<Task> queue) {
        this.queue = queue;
    }

    public void schedule() {
    
        boolean done = false;
        while(!done) {
            
            if(queue.size() != 0) {
                
                Task task = pickNextTask();
                if(task.getBurst() <= 0) {
                    queue.remove(task);
                } else if(task.getBurst() < quantum) {

                    CPU.run(task, task.getBurst());
                    queue.remove(task);

                } else if(task.getBurst() >= quantum) {

                    CPU.run(task, quantum);
                    task.setBurst(Math.abs(task.getBurst() - quantum));
                    queue.add(task);
                    queue.remove(0);

                }
            
            } else {

                done = true;

            }
        
        }

           

    }

    public Task pickNextTask() {
        return this.queue.get(0);        
    }

}
