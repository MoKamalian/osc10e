/*
 *
 *
 *
 *
 */



import java.util.List;


public class FCFS implements Algorithm {

  private List<Task> queueToRun;

  public FCFS(List<Task> queue) {
    this.queueToRun = queue;
  }


  public void schedule() {
    /* Pick the next task to run from the queue */
    int queueSize = queueToRun.size();
    for(int i=0; i<queueSize; i++) {
      Task taskToRun = pickNextTask();

      /* Run the task chosen in line */
      CPU.run(taskToRun, taskToRun.getBurst());

      /* update queue by removing the task that has completed runnning */
      this.queueToRun.remove(taskToRun);
    }
  }

  public Task pickNextTask() {
    return this.queueToRun.get(0);
  }


}