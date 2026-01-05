function minInterval(intervals: number[][], queries: number[]): number[] {
    // sort intervals by start time
    intervals.sort((a, b) => a[0] - b[0]);
    // sort queries but keep track of original indices
    const sortedQueries = queries.map((val, idx) => ({ val, idx })).sort((a, b) => a.val - b.val);
    const activeIntervals = new MinPriorityQueue<[number, number]>((val) => val[0]); // it contains valid intervals as per current query we are processing
    // we sorted query so that we don't have to process intervals again and again for each query
    // if an interval ends before the current query value, it will never be valid for any future queries
    // so we eliminate such intervals from our active intervals
    const results: number[] = new Array(queries.length).fill(-1);
    let i: number = 0;
    for (const query of sortedQueries) {
        // fill up valid intervals for this query
        while (i < intervals.length && intervals[i][0] <= query.val) {
            const [start, end] = intervals[i];
            activeIntervals.enqueue([end - start + 1, end]);
            i++;
        }
        // remove invalid intervals for this query
        while (!activeIntervals.isEmpty() && activeIntervals.front()[1] < query.val) {
            activeIntervals.dequeue();
        }
        results[query.idx] = activeIntervals.isEmpty() ? -1 : activeIntervals.front()[0];
    }

    return results;
};