import java.io.*;

public class Address {
    public static final int VIRTUAL_ADDRESS = 32;

    public static void main(String[] args) {
        if(args.length != 2) {
            throw new IllegalArgumentException("Invalid arguments");
        }

        int pageSize = Integer.parseInt(args[0]);
        int address = Integer.parseInt(args[1]);

        if(pageSize < 1024 || pageSize > 16384) {
            throw new IllegalArgumentException("Page size	 is not within the range of " +
                    "1024 - 16384");
        }

        if((pageSize & (pageSize - 1)) != 0) {
            throw new IllegalArgumentException("Page size is not a power of 2");
        }

        double virtualAddressSize = Math.pow(2, VIRTUAL_ADDRESS);
        double pages = virtualAddressSize / pageSize;
        int pageBits = (int) (Math.log(pages) / Math.log(2));
        int otherBits = VIRTUAL_ADDRESS - pageBits;

        int pageNumber = (address >> otherBits);
        int offset = (address & (pageSize - 1));

        System.out.println("The address " + address + " contains:");
        System.out.println("page number = " + pageNumber);
        System.out.println("offset = " + offset);
    }
}