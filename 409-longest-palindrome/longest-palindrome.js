/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
        const freq = {};

        // counting kr rhe hain sare character k freq ko
        for( let char of s )
        {
            if( freq[char] ) //agr value one hai toh freq increase kro
            {
                freq[char]++;
            }
            else
            {
                freq[char] = 1; //Nahi toh value zero se one kro aur kya
            }
        }

        var length = 0;
        let oddFound = false; //ek flag lelo taki pata chle ki ek aisa char tha jika freq one tha

        // ab dekho jo character even freq hai uska freq add krdo length wale variable me
        for( let count of Object.values(freq) )
        {
            if( count % 2 == 0 )
            {
                length += count;
            }
            else
            {
                length += count - 1; //yahan ye kr ki jo bhi odd freq wala character hai usko even time use kr lete hain....mtlb even time uska freq ka use kregein...
                oddFound = true;
            }
        }

        if( oddFound ) //yahan pr wo ek odd freq ko add kr rhe sirf ek ko middle me rakhne k liye...jse ki "racecar" me e middle element hai palindrome k liye
        {
            length += 1;
        }

        return length;
}