#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 64 // Define your buffer size as needed

// Function to read data from the file descriptor until a newline character or end of file is encountered
char *read_to_data_buffer(int fd, char *dataBuffer);

// Function to extract a line from the given string
char *get_line_from_data_buffer(char *dataBuffer);

// Function to create a new string with the remaining content after extracting a line
char *generate_new_data_buffer(char *dataBuffer);

// Function to get the next line from the file descriptor
char *get_next_custom_line(int fd);

int main() {
    // Example usage:
    // char *line = get_next_custom_line(file_descriptor);
    // ...
    return 0;
}

// Implementation of read_to_data_buffer function
char *read_to_data_buffer(int fd, char *dataBuffer)
{
    char *buffer;
    int read_bytes;

    buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if (!buffer)
        return (NULL);

    read_bytes = 1;

    // Continue reading until a newline character is found or end of file is reached
    while (!custom_strchr(dataBuffer, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(buffer);
            free(dataBuffer);
            return (NULL);
        }

        buffer[read_bytes] = '\0';
        dataBuffer = custom_strjoin(dataBuffer, buffer);
    }

    free(buffer);
    return (dataBuffer);
}

// Implementation of get_line_from_data_buffer function
char *get_line_from_data_buffer(char *dataBuffer)
{
    int i;
    char *line;

    i = 0;
    if (!dataBuffer[i])
        return (NULL);

    // Find the length of the line
    while (dataBuffer[i] && dataBuffer[i] != '\n')
        i++;

    // Allocate memory for the line
    line = ft_calloc((i + 2), sizeof(char));
    if (!line)
        return (NULL);

    i = 0;

    // Copy characters until a newline character is encountered
    while (dataBuffer[i] && dataBuffer[i] != '\n')
    {
        line[i] = dataBuffer[i];
        i++;
    }

    // Include the newline character in the line
    if (dataBuffer[i] == '\n')
    {
        line[i] = dataBuffer[i];
        i++;
    }

    line[i] = '\0';

    return (line);
}

// Implementation of generate_new_data_buffer function
char *generate_new_data_buffer(char *dataBuffer)
{
    int i;
    int j;
    char *newDataBuffer;

    i = 0;

    // Find the position of the newline character
    while (dataBuffer[i] && dataBuffer[i] != '\n')
        i++;

    // If no newline character is found, free the original string and return NULL
    if (!dataBuffer[i])
    {
        free(dataBuffer);
        return (NULL);
    }

    // Allocate memory for the new string without the extracted line
    newDataBuffer = ft_calloc((custom_strlen(dataBuffer) - i + 1), sizeof(char));
    if (!newDataBuffer)
        return (NULL);

    i++;

    j = 0;

    // Copy the remaining content after the newline character
    while (dataBuffer[i])
        newDataBuffer[j++] = dataBuffer[i++];

    newDataBuffer[j] = '\0';

    free(dataBuffer);

    return (newDataBuffer);
}

// Implementation of get_next_custom_line function
char *get_next_custom_line(int fd)
{
    char *line;
    static char *dataBuffer;

    // Check for invalid file descriptor or buffer size
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);

    // Read data into the temporary buffer
    dataBuffer = read_to_data_buffer(fd, dataBuffer);
    if (!dataBuffer)
        return (NULL);

    // Extract a line from the temporary buffer
    line = get_line_from_data_buffer(dataBuffer);

    // Update the temporary buffer to exclude the extracted line
    dataBuffer = generate_new_data_buffer(dataBuffer);

    return (line);
}

