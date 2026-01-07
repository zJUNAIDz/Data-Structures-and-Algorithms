// Bellman-ford, except for we are tracking prices instead of distance and ensuring distance does not go beyond k
// ts slow but constraint 2 <= n <= 100 makes it legal
function findCheapestPrice(n: number, flights: number[][], src: number, dst: number, k: number): number {
  let prices: number[] = Array(n + 1).fill(Infinity);
  prices[src] = 0;

  for (let i = 0; i <= k; i++) {
    // temp price for snapshot so we don't collide with prices updated in current round 
    const tempPrices = [...prices];
    for (const [from, to, price] of flights) {
      if (prices[from] === Infinity) continue; // ain't no one flyin for $Infinity gng
      // typical node relaxation logic 
      const newPrice = prices[from] + price;
      if (newPrice < tempPrices[to]) {
        tempPrices[to] = newPrice;
      }
    }
    prices = tempPrices;
  }
  return prices[dst] === Infinity ? -1 : prices[dst];
};
