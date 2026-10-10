# C++ Cybersecurity Examples

This repository contains comprehensive C++ examples demonstrating main cybersecurity use cases and best practices.

## Examples Overview

### 1. **Encryption/Decryption (AES-256-CBC)**
**Folder:** `1_encryption_aes`

Demonstrates:
- AES-256-CBC encryption/decryption
- Secure random key and IV generation
- OpenSSL EVP API usage
- Proper cipher context management

**Use Cases:**
- Protecting sensitive data at rest
- Secure data transmission
- File encryption

### 2. **Password Hashing**
**Folder:** `2_password_hashing`

Demonstrates:
- PBKDF2 key derivation with salt
- SHA-256 hashing
- Password strength validation
- Secure password storage and verification

**Use Cases:**
- User authentication systems
- Password storage
- Credential verification

### 3. **Secure Network Communication**
**Folder:** `3_secure_network`

Demonstrates:
- SSL/TLS context creation
- Secure socket operations
- Protocol version enforcement (TLS 1.2+)
- Input validation (IP addresses, ports)
- XSS prevention through sanitization

**Use Cases:**
- HTTPS connections
- Secure client-server communication
- API security

### 4. **Input Validation & Sanitization**
**Folder:** `4_input_validation`

Demonstrates:
- Email, username, phone validation
- Credit card validation (Luhn algorithm)
- IPv4 address validation
- HTML/SQL injection prevention
- Path traversal protection
- Command injection prevention
- XSS mitigation

**Use Cases:**
- Web application security
- Form validation
- API input filtering
- Database query protection

### 5. **Secure File Operations**
**Folder:** `5_secure_file_operations`

Demonstrates:
- Secure file permissions (chmod)
- File ownership verification
- Secure file deletion (overwriting)
- Atomic file operations
- Symlink attack prevention
- Temporary file handling
- File descriptor security

**Use Cases:**
- Sensitive data storage
- Configuration file protection
- Log file security
- Temporary file management

### 6. **Authentication & Authorization**
**Folder:** `6_authentication`

Demonstrates:
- User registration and login
- Secure token generation
- Token expiration management
- Role-based access control (RBAC)
- Account lockout after failed attempts
- Rate limiting
- Session management

**Use Cases:**
- User authentication systems
- API authentication
- Access control
- Session management

## Compilation Instructions

### Prerequisites

Install OpenSSL development libraries:

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install libssl-dev build-essential
```

**Fedora/RHEL:**
```bash
sudo dnf install openssl-devel gcc-c++
```

**macOS:**
```bash
brew install openssl
```

## Security Best Practices Covered

### Cryptography
- ✅ Use strong encryption algorithms (AES-256)
- ✅ Generate cryptographically secure random values
- ✅ Proper key and IV management
- ✅ Use authenticated encryption modes when possible

### Password Security
- ✅ Never store plaintext passwords
- ✅ Use strong key derivation functions (PBKDF2)
- ✅ Add salt to prevent rainbow table attacks
- ✅ Enforce password complexity requirements
- ✅ Implement account lockout mechanisms

### Network Security
- ✅ Use TLS 1.2 or higher
- ✅ Disable weak protocols (SSLv2, SSLv3, TLS 1.0, 1.1)
- ✅ Validate all network inputs
- ✅ Implement proper certificate validation

### Input Validation
- ✅ Validate all user inputs
- ✅ Use whitelist validation when possible
- ✅ Sanitize inputs to prevent injection attacks
- ✅ Implement proper error handling
- ✅ Use regex for pattern matching

### File Security
- ✅ Set restrictive file permissions (0600 for sensitive files)
- ✅ Verify file ownership before operations
- ✅ Prevent path traversal attacks
- ✅ Securely delete sensitive files
- ✅ Use atomic file operations

### Authentication & Authorization
- ✅ Implement secure session management
- ✅ Use token-based authentication
- ✅ Implement token expiration
- ✅ Use role-based access control
- ✅ Implement rate limiting
- ✅ Track and limit failed login attempts

## Common Vulnerabilities Prevented

| Vulnerability | Example(s) | Prevention Method |
|--------------|-----------|-------------------|
| **SQL Injection** | 4 | Input sanitization, parameterized queries |
| **XSS (Cross-Site Scripting)** | 3, 4 | HTML entity encoding, input validation |
| **Path Traversal** | 4, 5 | Path validation, sanitization |
| **Command Injection** | 4 | Command sanitization, whitelist validation |
| **Weak Cryptography** | 1, 2 | Strong algorithms (AES-256, SHA-256) |
| **Insecure Storage** | 5 | File permissions, encryption |
| **Broken Authentication** | 6 | Secure tokens, account lockout, rate limiting |
| **Sensitive Data Exposure** | 1, 5 | Encryption, secure deletion |
| **Broken Access Control** | 6 | RBAC, token validation |
| **Man-in-the-Middle** | 3 | TLS/SSL, certificate validation |

## Important Notes

1. **Production Use**: These examples are for educational purposes. For production systems:
   - Use established security libraries
   - Conduct security audits
   - Follow OWASP guidelines
   - Keep dependencies updated

2. **OpenSSL Deprecation**: Some OpenSSL functions may be deprecated in newer versions. Update accordingly.

3. **Error Handling**: Production code should have more comprehensive error handling and logging.

4. **Testing**: Always test security implementations thoroughly in isolated environments.

5. **Compliance**: Ensure compliance with relevant standards (PCI-DSS, GDPR, HIPAA, etc.).

## Additional Resources

- [OWASP Top 10](https://owasp.org/www-project-top-ten/)
- [OpenSSL Documentation](https://www.openssl.org/docs/)
- [CWE (Common Weakness Enumeration)](https://cwe.mitre.org/)
- [NIST Cybersecurity Framework](https://www.nist.gov/cyberframework)
- [C++ Core Guidelines - Security](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

## License

These examples are provided for educational purposes. Use at your own risk.

**Remember**: Security is not a one-time implementation but an ongoing process. Stay updated with the latest security practices and vulnerabilities.
