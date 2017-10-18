
#define NUMERR_LONG     0x80000000
#define MAX_LONG        2147483647

#define NONBLOCKING     0
#define BLOCKING        1

#define NOEXEC          0
#define EXEC            1

#define RXBUFEMPTY     -1
#define RXOVERFLOW     -2

#define RXBUFSIZE      32
#define COMMANDCOUNT   41		// must match COMMANDS and gCOMMANDS below



extern void serSendByte( uint8_t ch );
extern void serSendString( uint8_t *ch );
extern void serSendStringDebug( uint8_t *ch1, int32_t val, uint8_t *ch2);
extern uint8_t *lltoa( uint8_t *buffer, long i );

