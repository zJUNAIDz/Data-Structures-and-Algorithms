import {
  MaxPriorityQueue,
} from '@datastructures-js/priority-queue';

function leastInterval(tasks: string[], n: number): number {
  // if cooldown period is irrelevant
  if (n === 0) return tasks.length;

  let time = 0;
  const count: number[] = Array(26).fill(0);
  for (const task of tasks) {
    count[task.charCodeAt(0) - 65]++; // task is denoted by uppercase letter so 65(A)
  }
  const pq = new MaxPriorityQueue<number>();
  for (const cnt of count) {
    if (cnt > 0) { //avoid 0 values to make pq.isEmpty() useful
      pq.enqueue(cnt);
    }
  }
  while (!pq.isEmpty()) {
    const coolingTasks: number[] = []; // temp buffer to insert updated heap count values (executed task with now decremented count) [tasks waiting out their cooldown]
    let taskExecuted = 0; // useful for last cycle iteration to avoid adding idle time at the end which wound result in incorrect time
    const cycle = n + 1
    for (let i = 0; i < cycle; i++) {
      if (pq.isEmpty()) { // early exit
        break;
      }
      const top = pq.dequeue()!;
      taskExecuted++;
      if (top > 1) { // avoid adding zero values to heap
        coolingTasks.push(top - 1);
      }
    }
    for (const num of coolingTasks) { // refill heap with updated counts
      pq.enqueue(num)
    }
    time += pq.isEmpty() ? taskExecuted : n + 1; // if heap is empty then all tasks is completed so we must not force idle time in the end and just add number of task executed.
  }
  return time;
};
function getIdx(char: string): number {
  return char.charCodeAt(0) - "A".charCodeAt(0);
}
